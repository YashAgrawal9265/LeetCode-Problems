class Node{
public:
    int value, key, cnt;
    Node* prev, *next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        cnt = 1;
        prev = NULL;
        next = NULL;
    }
};
class List{
public:
    Node* head, *tail;
    int size;
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void deleteNode(Node* node){
        size--;
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* node){
        size++;
        Node* curNodeAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = curNodeAfterHead;
        curNodeAfterHead->prev = node;
    }
};
class LFUCache {
private:
    map<int,Node*> keyNode;
    map<int,List*> freqList;
    int mxSize;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        keyNode.clear();
        freqList.clear();
        mxSize = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        List* list = freqList[node->cnt];
        list->deleteNode(node);
        if(minFreq == node->cnt and list->size == 0){
            minFreq++;
        }
        List* newList = new List();
        if(freqList.find(node->cnt+1) != freqList.end()){
            newList = freqList[node->cnt + 1];
        }
        node->cnt++;
        newList->insertAfterHead(node);
        freqList[node->cnt] = newList;
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int value = node->value;
            updateFreqList(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mxSize == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else{
            if(curSize == mxSize){
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* newList = new List();
            if(freqList.find(minFreq) != freqList.end()){
                newList = freqList[minFreq];
            }
            Node* newNode = new Node(key,value);
            newList->insertAfterHead(newNode);
            keyNode[key] = newNode;
            freqList[minFreq] = newList;
        }
    }
};
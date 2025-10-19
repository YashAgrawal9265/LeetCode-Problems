class Node{
public:
    int key, value, cnt;
    Node* next,*prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

class List{
public:
    int size;
    Node* head, *tail;
    List(){
        size = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void addFront(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
        size++;
    }
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
private:
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqList;
    int cacheSize;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        keyNode.clear();
        freqList.clear();
        cacheSize = capacity;
        minFreq = 1;
        curSize = 0;
    }
    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq and freqList[node->cnt]->size == 0){
            minFreq++;
        }
        List* newList = new List();
        if(freqList.find(node->cnt+1) != freqList.end()){
            newList = freqList[node->cnt+1];
        }
        node->cnt += 1;
        newList->addFront(node);
        keyNode[node->key] = node;
        freqList[node->cnt] = newList;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cacheSize == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else{
            if(curSize == cacheSize){
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;

            List* list = new List();
            if(freqList.find(minFreq) != freqList.end()){
                list = freqList[minFreq];
            }
            Node* newNode = new Node(key,value);
            keyNode[key] = newNode;
            list->addFront(newNode);
            freqList[minFreq] = list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
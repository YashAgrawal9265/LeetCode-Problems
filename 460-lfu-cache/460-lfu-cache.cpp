class Node{
public:
    int key;
    int value;
    int cnt;
    Node* prev;
    Node* next;
    Node(int a, int b){
        key = a;
        value = b;
        cnt = 1;
        prev = NULL;
        next = NULL;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    int size;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    void addFront(Node* node){
        size++;
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    void deleteNode(Node* node){
        size--;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

class LFUCache {
private:
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqListMap;
    int mxSize;
    int minFreq;
public:
    LFUCache(int capacity) {
        mxSize = capacity;
        minFreq = 1;
    }
    
    void updateFreqList(Node* node){
        int cnt = node->cnt;
        freqListMap[cnt]->deleteNode(node);
        if(cnt == minFreq and freqListMap[cnt]->size == 0){
            minFreq++;
        }
        
        List* list = new List();
        if(freqListMap.find(cnt + 1) != freqListMap.end()){
            list = freqListMap[cnt + 1];
        }
        node->cnt++;
        list->addFront(node);
        // keyNode[node->key] = node;
        freqListMap[cnt + 1] = list;
    }
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        int val = keyNode[key]->value;
        
        updateFreqList(keyNode[key]);
        return val;
        
    }
    
    void put(int key, int value) {
        if(mxSize == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            keyNode[key]->value = value;
            updateFreqList(keyNode[key]);
        }
        else{
            if(keyNode.size() == mxSize){
                List* list = freqListMap[minFreq];
                
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
            }
            List* list = new List();
            Node* node = new Node(key,value);
            minFreq = 1;
            if(freqListMap.find(1) != freqListMap.end()){
                list = freqListMap[1];
            }
            list->addFront(node);
            keyNode[key] = node;
            freqListMap[1] = list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
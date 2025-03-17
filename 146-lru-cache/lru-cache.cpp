class Node{
public:
    int key, value;
    Node* prev, *next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,Node*> mp;
    Node* head, *tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* node){
        Node* curNodeAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = curNodeAfterHead;
        curNodeAfterHead->prev = node;
    }
    int get(int key) {
        // if key is present in map
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mp.size() == capacity){
            // delete least recently used cache which is before tail
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            }
            Node* newNode = new Node(key,value);
            mp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
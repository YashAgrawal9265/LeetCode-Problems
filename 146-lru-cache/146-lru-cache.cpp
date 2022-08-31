class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int a, int b){
        key = a;
        value = b;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
private:
    unordered_map<int,Node*> mp;
    Node*head;
    Node* tail;
    int capacity;
    
    Node* insertNodeAtFront(int key, int val){
        Node* node = new Node(key,val);
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        return node;
    }
    void deleteLastNode(){
        Node* toDelete = tail->prev;
        toDelete->prev->next = tail;
        tail->prev = toDelete->prev;
        mp.erase(toDelete->key);
        delete toDelete;
    }
    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
public:
    LRUCache(int size) {
        mp.clear();
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        capacity = size;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        int value = mp[key]->value;
        deleteNode(mp[key]);
        mp[key] = insertNodeAtFront(key,value);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            mp[key] = insertNodeAtFront(key,value);
        }
        else{
            if(mp.size() == capacity){
                deleteLastNode();
            }
            mp[key] = insertNodeAtFront(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
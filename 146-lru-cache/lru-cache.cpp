class Node{
public:
    int val;
    int key;
    Node* next;
    Node* prev;
public:
    Node(int key,int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> nodeMp;
    Node* head, *tail;
    int cacheSize;
    void deleteNode(Node*& node){
        int key = node->key;
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if(prevNode) prevNode->next = nextNode;
        if(nextNode) nextNode->prev = prevNode;
        nodeMp.erase(key);
    }
    void insertAtFront(Node*& node){
        int key = node->key;
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
        nodeMp[key] = node;
    }
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        nodeMp.clear();
    }
    
    int get(int key) {
        cout<<"get "<<key<<endl;
        // cout<<nodeMp.size()<<" "<<key<<endl;
        if(nodeMp.find(key) == nodeMp.end()) return -1;
        Node* node = nodeMp[key];
        int value = node->val;
        deleteNode(node);

        Node* newNode = new Node(key,value);
        insertAtFront(newNode);
        return value;
    }
    
    void put(int key, int value) {
        Node* newNode = new Node(key,value);
        if(nodeMp.find(key) != nodeMp.end()){
            deleteNode(nodeMp[key]);
        }
        else if(nodeMp.size() == cacheSize){
            deleteNode(tail->prev);
        }
        insertAtFront(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
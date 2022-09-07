struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        if(links[ch-'a'] != NULL) return true;
        return false;
    }
    
    void put(char ch, Node*& node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
    
    
    
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto it: word){
            if(!node->containsKey(it)){
                Node* newNode = new Node();
                node->put(it,newNode);
            }
            node = node->get(it);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto it: word){
            if(!node->containsKey(it)){
                return false;
            }
            node = node->get(it);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(auto it: word){
            if(!node->containsKey(it)){
                return false;
            }
            node = node->get(it);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
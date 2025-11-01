struct Node{
    Node* links[26];
    bool flag = false;

    bool containskey(char ch){
        return links[ch-'a'] != NULL;
    }

    void insertNode(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getNode(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag == true;
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
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->insertNode(word[i], new Node());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }

    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->getNode(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->getNode(word[i]);
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
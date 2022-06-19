struct Node{
    Node* links[27];
    int idx;
    
    bool containsKey(char ch){
        if(links[ch-'a'] == NULL) return false;
        return true;
    }
    void put(char ch, Node*& node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string& word, int index){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                Node* newNode = new Node();
                node->put(word[i],newNode);
            }
            node = node->get(word[i]);
            node->idx = index;
        }
    }
    int search(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return -1;
            }
            node = node->get(word[i]);
        }
        return node->idx;
    }
};
class WordFilter {
private:
    Trie trie;
public:
    WordFilter(vector<string>& words) {
        int idx = 0;
        for(auto &it: words){
            int n = it.size();
            string str = it;
            for(int i = n-1;i>=0;i--){
                string temp = str.substr(i) + "{" + str;
                trie.insert(temp,idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        return trie.search(suffix + "{" + prefix);
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
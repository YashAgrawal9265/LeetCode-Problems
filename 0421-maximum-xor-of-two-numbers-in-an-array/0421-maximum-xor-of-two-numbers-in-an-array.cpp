struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node* node = root;
        int mxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)){
                mxNum = (1<<i) | mxNum;
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return mxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it: nums){
            trie.insert(it);
        }
        int mxNum = 0;
        for(auto it: nums){
            mxNum = max(mxNum,trie.getMax(it));
        }
        return mxNum;
    }
};
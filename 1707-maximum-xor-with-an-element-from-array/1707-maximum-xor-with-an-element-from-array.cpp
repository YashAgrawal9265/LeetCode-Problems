struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
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
                mxNum = mxNum | (1<<i);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i][1],{queries[i][0],i}});
        }
        vector<int> ans(queries.size());
        sort(v.begin(),v.end());
        sort(nums.begin(),nums.end());
        
        Trie trie;
        int j = 0, i = 0;
        
        while(i < v.size()){
           
            while(j < nums.size() and nums[j] <= v[i].first){
                
                trie.insert(nums[j]);
                j++;
            }
          
            if(j == 0) ans[v[i].second.second] = -1;
            else ans[v[i].second.second] = trie.getMax(v[i].second.first);
            i++;
        }
        return ans;
    }
};
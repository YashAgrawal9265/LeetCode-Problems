class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        unordered_map<string,vector<string>> mp;
        for(auto &it: products){
            string temp = "";
            for(int i=0;i<it.size();i++){
                temp += it[i];
                if(mp[temp].size() == 3) continue;
                mp[temp].push_back(it);
            }
        }
        vector<vector<string>> result;
        string temp = "";
        for(int i=0;i<searchWord.size();i++){
            temp += searchWord[i];
            result.push_back(mp[temp]);
        }
        return result;
    }
};
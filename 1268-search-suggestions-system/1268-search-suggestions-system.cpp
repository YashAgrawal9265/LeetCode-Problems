class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string,set<string>> mp;
        for(auto &it: products){
            string temp = "";
            for(int i=0;i<it.size();i++){
                temp += it[i];
                mp[temp].insert(it);
            }
        }
        vector<vector<string>> result;
        string temp = "";
        for(int i=0;i<searchWord.size();i++){
            temp += searchWord[i];
            vector<string> arr;
            int k = 3;
            auto &st = mp[temp];
            for(auto it = st.begin(); it != st.end() and k; it++){
                k--;
                arr.push_back(*it);
            }
            result.push_back(arr);
        }
        return result;
    }
};
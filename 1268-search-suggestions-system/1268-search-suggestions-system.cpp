class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int n = products.size();
        vector<vector<string>> result;
        string prefix = "";
        for(int i=0;i<searchWord.size();i++){
            prefix += searchWord[i];
            int idx = lower_bound(products.begin(),products.end(),prefix) - products.begin();
            vector<string> temp;
            for(int j=idx;j<min(idx+3,n) && products[j].compare(0,prefix.size(),prefix) == 0;j++){
                temp.push_back(products[j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};
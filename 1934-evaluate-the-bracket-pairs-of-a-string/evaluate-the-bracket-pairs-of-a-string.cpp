class Solution {
public:
    string evaluate(string str, vector<vector<string>>& knowledge) {
        int n = str.size();
        unordered_map<string,string> mp;
        for(auto it: knowledge){
            string key = it[0], value = it[1];
            mp[key] = value;
        }
        string result = "";
        int i = 0;
        while(i < n){
            if(str[i] == '('){
                i++;
                string key = "";
                while(str[i] != ')'){
                    key += str[i];
                    i++;
                }
                if(mp.find(key) != mp.end()){
                    result += mp[key];
                }
                else{
                    result += "?";
                }
            }
            else{
                result += str[i];
            }

            i++;
        }
        return result;
    }
    
};
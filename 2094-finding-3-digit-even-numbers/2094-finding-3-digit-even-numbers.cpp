class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<char,int> mp;
        for(auto it: digits){
            mp[it+'0']++;
        }
        vector<int> result;
        for(int i=100;i<=999;i++){
            if(i % 2 == 0){
                
                string str = to_string(i);    
                unordered_map<char,int> mp2;
                mp2[str[0]]++;
                mp2[str[1]]++;
                mp2[str[2]]++;
                bool flag = true;
                for(auto &it: mp2){
                    if(mp[it.first] < it.second){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    result.push_back(i);
                }
            }
            
        }
        return result;
    }
};
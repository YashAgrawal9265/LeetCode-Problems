class Solution {
public:
    int romanToInt(string str) {
        int n = str.size();
        unordered_map<char,int> mp;
        mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50,
        mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
        
        int num = 0;
        int i = 0;
        while(i < n){
            if(i+1 < n and  mp[str[i+1]] > mp[str[i]]){
                num += (mp[str[i+1]] - mp[str[i]]);
                i += 2;
            }
            else{
                num += mp[str[i]];
                i++;
            }
        }
        return num;
        
    }
};
class Solution {
public:
    string minWindow(string str, string pattern) {
        int n = str.size();
        // if(n < pattern.size()){
        //     return "";
        // }
        
    
        // map for storing characters
        vector<int> mp(256,0); 
        
        
        for(int i=0;i<pattern.size();i++){
            mp[pattern[i]]++;
        }
        
        int ele = 0;
        int pattSize = pattern.size();

        int left = 0, right = 0;
        int mnLen = INT_MAX;
        int stIdx;
        while(right < n){
            if(mp[str[right]] > 0){
                ele++;
            }
            mp[str[right]]--;
            while(ele == pattSize){
                
                if(right - left + 1 < mnLen){
                    stIdx = left;
                    mnLen = right - left + 1;
                }
                if(mp[str[left]] >= 0){
                    ele--;
                }
                mp[str[left]]++;
                left++;
                
                // mnLen = min(mnLen, right - left + 1);
            }
            right++;
        }
       
        if(mnLen == INT_MAX){
            return "";
        }
        return str.substr(stIdx,mnLen);
    }
};
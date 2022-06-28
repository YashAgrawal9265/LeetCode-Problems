class Solution {
public:
    int minDeletions(string str) {
        int n = str.size();
        vector<int> mp(26,0);
        for(int i=0;i<n;i++){
            mp[str[i]-'a']++;
        }
        
        vector<int> freq;
        for(int i=0;i<26;i++){
            if(mp[i] != 0)
                freq.push_back(mp[i]);
        }
        int count = 0;
        sort(freq.begin(),freq.end(),greater<int>());
        int allowed_freq = freq[0];
        for(int i=0;i<freq.size();i++){
            if(freq[i] > allowed_freq){
                if(allowed_freq >= 0){
                    count += (freq[i] - allowed_freq);
                }
                else{
                    count += freq[i];
                }
            }
            allowed_freq = min(freq[i]-1,allowed_freq-1);
        }
        return count;
    }
};
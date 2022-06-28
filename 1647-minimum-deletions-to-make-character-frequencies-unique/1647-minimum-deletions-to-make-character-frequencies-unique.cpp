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
        
        unordered_set<int> st;
        int count = 0;
        n = freq.size();
        for(int i=0;i<n;i++){
           while(freq[i] and st.find(freq[i]) != st.end()){
               freq[i]--;
               count++;
           }
           if(freq[i]) st.insert(freq[i]);
            
        }
        return count;
    }
};
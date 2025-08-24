class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Mp(26, 0), s2Mp(26,0);
        if(s2.size() < s1.size()) return false;
        int l = 0, r = 0;
        int matches = 0;
        while(r < s1.size()){
            s1Mp[s1[r]-'a']++;
            s2Mp[s2[r]-'a']++;
            r++;
        }
        for(int i=0;i<26;i++){
            if(s1Mp[i] == s2Mp[i]) matches++;
        }
        while(r < s2.size()){
            if(matches == 26) return true;
            int index = s2[r] - 'a';
            s2Mp[index]++;
            if(s1Mp[index] == s2Mp[index]) matches++;
            else if(s1Mp[index]+1 == s2Mp[index]) matches--;
            r++;

            index = s2[l] - 'a';
            s2Mp[index]--;
            if(s1Mp[index] == s2Mp[index]) matches++;
            else if(s1Mp[index]-1 == s2Mp[index]) matches--;
            l++;
        }
        return matches == 26;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Mp(26, 0), s2Mp(26,0);
        if(s2.size() < s1.size()) return false;
        int l = 0, r = 0;
        while(r < s1.size()){
            s1Mp[s1[r]-'a']++;
            s2Mp[s2[r]-'a']++;
            r++;
        }
        if(s1Mp == s2Mp) return true;
        while(r < s2.size()){
            s2Mp[s2[r] - 'a']++;
            s2Mp[s2[l] - 'a']--;
            if(s1Mp == s2Mp) return true;
            r++;
            l++;
        }
        return false;
    }
};
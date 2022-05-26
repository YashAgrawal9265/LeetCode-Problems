class Solution {
public:
    bool checkAlmostEquivalent(string str1, string str2) {
        int n = str1.size();
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }
        for(int i=0;i<n;i++){
            if(abs(mp1[str1[i]] - mp2[str1[i]]) > 3) return false;
            if(abs(mp1[str2[i]] - mp2[str2[i]]) > 3) return false;
        }
        return true;
    }
};
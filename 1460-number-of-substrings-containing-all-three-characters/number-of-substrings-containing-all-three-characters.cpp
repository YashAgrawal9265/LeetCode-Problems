class Solution {
public:
    int numberOfSubstrings(string str) {
        int n = str.size();
        int l = 0, r = 0, ans = 0;
        vector<int> lastSeen(3,-1);
        for(int i=0;i<n;i++){
            lastSeen[str[i]-'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                ans += (1 + min(lastSeen[0],min(lastSeen[1],lastSeen[2])));
            }
        }
        return ans;
    }
};
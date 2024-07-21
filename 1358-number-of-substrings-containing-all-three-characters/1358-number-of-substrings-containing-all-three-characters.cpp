class Solution {
public:
    int numberOfSubstrings(string str) {
        int n = str.size();
        vector<int> lastSeen(3,-1);
        int count= 0;
        for(int i=0;i<n;i++){
            lastSeen[str[i]-'a'] = i;
            if(lastSeen[0] != -1 and lastSeen[1] != -1 and lastSeen[2] != -1){
                count += 1 + min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
            }
        }
        return count;
    }
};
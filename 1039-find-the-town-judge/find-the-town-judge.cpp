class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> mp;
        for(auto it: trust){
            int i = it[0], j = it[1];
            mp[j]++;
            mp[i]--;
        }
        for(int i=1;i<=n;i++){
            if(mp[i] == n-1) return i;
        }
        return -1;
        
    }
};
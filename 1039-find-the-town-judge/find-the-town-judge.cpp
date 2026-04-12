class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,set<int>> mp;
        for(auto it: trust){
            int i = it[0], j = it[1];
            // i knows j
            // mp[i] = j; 
            mp[i].insert(j);
        }
        int i = 1, j = n;
        // cout<<mp[1].size()<<endl;
        // cout<<(mp[1].find(2) != mp[1].end())<<endl;
        while(i < j){
            if(mp[i].find(j) != mp[i].end()){
                i++;
            }
            else{
                j--;
            }
        }

        int potential = i;
        // cout<<potential;
        for(int k=1;k<=n;k++){
            if(potential == k) continue;
            if((mp[k].find(potential) == mp[k].end()) || (mp[potential].find(k) != mp[potential].end())){
                // cout<<potential<<" "<<k<<endl;
                // cout<<mp[potential]<<endl;
                // cout<<mp[k]<<endl;
                return -1;
            }
        }
        return potential;

    }
};
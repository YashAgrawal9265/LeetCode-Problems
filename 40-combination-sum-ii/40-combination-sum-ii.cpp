class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp, int idx, int target, int n){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(i > idx and candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(candidates,result,temp,i+1,target-candidates[i],n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,result,temp,0,target,n);
        return result;
    }
};
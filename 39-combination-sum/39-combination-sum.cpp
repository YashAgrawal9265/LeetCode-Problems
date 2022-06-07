class Solution {
public:
    void solve(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& result, int idx, int target){
        if(idx < 0){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }
        solve(candidates,temp,result,idx-1,target);
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            solve(candidates,temp,result,idx,target-candidates[idx]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(candidates,temp,result,candidates.size()-1,target);
        return result;
    }
};
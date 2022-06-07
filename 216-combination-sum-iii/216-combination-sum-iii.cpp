class Solution {
public:
    void solve(int num,vector<vector<int>>& result, vector<int>& temp, int target, int count){
        if(num == 10){
            if(target == 0 and count == 0){
                result.push_back(temp);
            }
            return;
        }
        solve(num+1,result,temp,target,count);
        if(num <= target and count > 0){
            temp.push_back(num);
            solve(num+1,result,temp,target-num,count-1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(1,result,temp,n,k);
        return result;
    }
};
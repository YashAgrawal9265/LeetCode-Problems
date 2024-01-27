class Solution {
private:
    void solve(vector<int>& temp, vector<vector<int>>& result, int target, int size, int idx, int n){
        
        if(idx > n){
            if(target == 0 and temp.size() == size) result.push_back(temp);
            return;
        }
        if(target - idx >= 0 and temp.size() < size){
            temp.push_back(idx);
            solve(temp,result,target-idx,size,idx+1,n);
            temp.pop_back();
        }
        solve(temp,result,target,size,idx+1,n);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> result;
        int target = n;
        solve(temp,result,target,k,1,9);
        return result;
    }
};
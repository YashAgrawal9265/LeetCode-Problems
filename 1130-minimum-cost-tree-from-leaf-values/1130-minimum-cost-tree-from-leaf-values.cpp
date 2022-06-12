class Solution {
public:
    // first = maximum leaf value
    // second = total sum of non-leaf values
    pair<int,int> solve(vector<int>& arr, int st, int en,map<pair<int,int>,pair<int,int>>& dp){
        if(st == en){
            return {arr[st],0};
        }
        if(dp.find({st,en}) != dp.end()) return dp[{st,en}];
        int mini = INT_MAX;
        pair<int,int> temp;
        for(int i=st;i<en;i++){
            pair<int,int> left = solve(arr,st,i,dp);
            pair<int,int> right = solve(arr,i+1,en,dp);
            int totSum = (left.first*right.first) + left.second + right.second;
            if(totSum < mini){
                temp.first = max(left.first,right.first);
                temp.second = totSum;
                mini = totSum;
            }
        }
        return dp[{st,en}] = temp;
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int>,pair<int,int>> dp;
        return solve(arr,0,n-1,dp).second;
    }
};
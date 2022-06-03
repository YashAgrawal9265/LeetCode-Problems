class Solution {
public:
    int solve(vector<pair<int,int>>& arr, int idx, int zeroCount, int oneCount, vector<vector<vector<int>>>& dp){
        if(idx == 0){
            if(arr[idx].first <= zeroCount and arr[idx].second <= oneCount) return 1;
            return 0;
        }
        if(dp[idx][zeroCount][oneCount] != -1) return dp[idx][zeroCount][oneCount];
        int nopick = solve(arr,idx-1,zeroCount,oneCount,dp);
        int pick = 0;
        if(arr[idx].first <= zeroCount and arr[idx].second <= oneCount){
            pick = 1 + solve(arr,idx-1,zeroCount-arr[idx].first, oneCount-arr[idx].second,dp);
        }
        return dp[idx][zeroCount][oneCount] = max(pick,nopick);
    }
    int findMaxForm(vector<string>& str, int m, int n) {
        
        vector<pair<int,int>> arr(str.size());
        for(int i=0;i<str.size();i++){
            string temp = str[i];
            int count1 = 0, count0 = 0;
            for(auto it: str[i]){
                if(it == '0') count0++;
                else if(it == '1') count1++;
            }
            arr[i].first = count0;
            arr[i].second = count1;
        }
        vector<vector<vector<int>>> dp(str.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(arr,str.size()-1,m,n,dp);
    }
};
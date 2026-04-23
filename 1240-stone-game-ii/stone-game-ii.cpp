class Solution {
public:
    int dp[105][105];
    int solve(vector<int>& arr, int idx, int M, int n){
        if(idx == n) return 0;
        if(dp[idx][M] != -1) return dp[idx][M];
        int stone = 0;
        int maxi = -1e8;
        for(int x=0;x<2*M;x++){
            if(idx + x < n){
                stone += arr[idx+x];
                int op1 = stone - solve(arr,idx+x+1,max(M,x+1),n);
                maxi = max(maxi,op1);
            }
        }
        return dp[idx][M] = maxi;
    }
    int stoneGameII(vector<int>& arr) {
        int tot = 0;
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        for(auto it: arr) tot += it;
        return (tot + solve(arr,0,1,n)) / 2;
    }
};
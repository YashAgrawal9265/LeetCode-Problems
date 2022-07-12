class Solution {
private:
    unordered_map<int,bool> dp;
public:
    bool solve(vector<int>& arr, int& vis, int idx, int target, int sideLength, int sides){
        if(sides == 0) return true;
        if(target == 0){
            return dp[vis] = solve(arr,vis,0,sideLength,sideLength,sides-1);
        }
        if(dp.find(vis) != dp.end()) return dp[vis];
        for(int i=idx;i<arr.size();i++){
           if(!(vis & (1 << i))){
                if(arr[i] <= target){
                    vis |= (1 << i);
                    if(solve(arr,vis,i+1,target-arr[i],sideLength,sides)){
                        return dp[vis] = true;
                    }
                    vis &= ~(1 << i);
                }
               else{
                   break;
               }
           }
        }
        
        return dp[vis] = false;
    }
    bool makesquare(vector<int>& arr) {
        dp.clear();
        int n = arr.size();
        int sum = 0;
        sort(arr.begin(),arr.end());
        for(auto it: arr) sum += it;
        if(sum % 4 != 0 or n == 0) return false;
        int vis = 0;
        return solve(arr,vis,0,sum/4,sum/4,4);
    }
};
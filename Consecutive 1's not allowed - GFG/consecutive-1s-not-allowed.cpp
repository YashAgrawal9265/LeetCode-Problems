// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int mod = 1e9 + 7;
    
// 	long long solve(int n, bool one){
// 	    if(n == 0){
// 	        return 1;
// 	    }
// 	    if(dp[n][one] != -1) return dp[n][one];
// 	    long long pick = 0;
// 	    if(one){
// 	        pick = solve(n-1,false) % mod;
// 	    }
// 	    long long nopick = solve(n-1,true) % mod;
// 	    return dp[n][one] = (pick + nopick) % mod;
// 	}
	ll countStrings(int n) {
	    
	    vector<int> dp(2,1), cur(2);
	    
	    for(int i=1;i<=n;i++){
	        for(int one = 0; one <=1; one++){
	            long long pick = 0;
        	    if(one){
        	        pick = dp[0] % mod;
        	    }
        	    long long nopick = dp[1] % mod;
        	    cur[one] = (pick + nopick) % mod;
	        }
	        dp = cur;
	    }
	    return dp[1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int mod = 1e9 + 7;
    long long dp[100009][2];
	long long solve(int n, bool one){
	    if(n == 0){
	        return 1;
	    }
	    if(dp[n][one] != -1) return dp[n][one];
	    long long pick = 0;
	    if(one){
	        pick = solve(n-1,false) % mod;
	    }
	    long long nopick = solve(n-1,true) % mod;
	    return dp[n][one] = (pick + nopick) % mod;
	}
	ll countStrings(int n) {
	    memset(dp,-1,sizeof(dp));
	    return solve(n,true);
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
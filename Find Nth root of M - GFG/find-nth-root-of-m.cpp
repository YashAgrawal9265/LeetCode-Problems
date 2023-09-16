//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long func(int mid, int n,int m){
	    long long ans = 1;
	    for(int i=1;i<=n;i++){
	        ans *= mid;
	        if(ans > m) return m+1;
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    int low = 1, high = m;
	    while(high - low > 1){
	        int mid = (low + high )>>1;
	        
	        if(func(mid,n,m) <= m){
	            low = mid;
	        }
	        else{
	            high = mid-1;
	        }
	    }
	    if(func(low,n,m) == m) return low;
	    if(func(high,n,m) == m) return high;
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
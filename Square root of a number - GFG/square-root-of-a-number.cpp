//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x == 1) return 1;
        long long int low = 1, high = x/2;
        while(high - low > 1){
            long long int mid = (low + high) >> 1;
            if(mid*mid <= x){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        if(high*high <= x) return high;
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
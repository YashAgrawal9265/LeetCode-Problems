//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  private:
    bool isValid(int arr[], long long mxTime, int painters, int n){
        long long Time = 0;
        for(int i=0;i<n;i++){
            Time += arr[i];
            if(Time > mxTime){
                painters--;
                Time = arr[i];
            }
        }
        if(Time <= mxTime) painters--;
        if(painters < 0) return false;
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long low = LLONG_MIN, high = 0;
        for(int i=0;i<n;i++){
            low = max(low,1LL*arr[i]);
            high += arr[i];
        }
        while(high - low > 1){
            long long mid = (low + high) >> 1;
            if(isValid(arr,mid,k,n)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(isValid(arr,low,k,n)) return low;
        return high;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
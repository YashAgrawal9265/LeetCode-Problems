//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    bool isValid(int arr[], int pages, int m, int n){
        int totPages = 0;
        for(int i=0;i<n;i++){
            totPages += arr[i];
            if(totPages > pages){
                m--;
                totPages = arr[i];
            }
        }
        if(totPages <= pages) m--;
        if(m < 0) return false;
        return true;
    }
    public:
    int findPages(int arr[], int n, int m) 
    {
        if(n < m) return -1;
        int low = INT_MIN;
        int high = 0;
        for(int i=0;i<n;i++){
            low = max(low,arr[i]);
            high += arr[i];
        }
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(isValid(arr,mid,m,n)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        if(isValid(arr,low,m,n)) return low;
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
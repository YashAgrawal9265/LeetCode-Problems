//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isValid(vector<int>& arr, int dist, int cows){
    int prevCow = arr[0];
    cows--;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-prevCow >= dist){
            prevCow = arr[i];
            cows--;
        }
        if(cows <= 0) return true;
    }
    return false;
}
    int solve(int n, int k, vector<int> &arr) {
    
        sort(arr.begin(),arr.end());
    int low = 0, high = *max_element(arr.begin(),arr.end());
    while(high - low > 1){
        int mid = (low + high) >> 1;
        if(isValid(arr,mid,k)){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    if(isValid(arr,high,k)) return high;
    return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
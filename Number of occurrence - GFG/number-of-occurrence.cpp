//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int firstPos(int arr[], int n, int key){
	    int low = 0, high = n - 1;
	    while(high - low > 1){
	        int mid = (low + high) >> 1;
	        if(arr[mid] < key){
	            low = mid + 1;
	        }
	        else{
	            high = mid;
	        }
	    }
	    int idx = n;
	    if(arr[low] >= key) idx = low;
	    else if(arr[high] >= key) idx = high;
	    if(idx < n and arr[idx] == key) return idx;
	    return -1;
	}
	int lastPos(int arr[], int n, int key){
	    int low = 0, high = n - 1;
	    while(high - low > 1){
	        int mid = (low + high) >> 1;
	        if(arr[mid] <= key){
	            low = mid + 1;
	        }
	        else{
	            high = mid;
	        }
	    }
	    int idx = n;
	    if(arr[low] > key) idx = low;
	    else if(arr[high] > key) idx = high;
	    idx--;
	    if(idx >= 0 and arr[idx] == key) return idx;
	    return -1;
	}
	int count(int arr[], int n, int x) {
	    int first = firstPos(arr,n,x); 
	    int last = lastPos(arr,n,x);
	    
	    if(first == -1) return 0;
	    return last - first + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
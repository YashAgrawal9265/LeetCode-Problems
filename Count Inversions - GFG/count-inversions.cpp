//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long merge(long long arr[], int left, int mid, int right){
        vector<long long> temp;
        
        int i = left, j = mid+1;
        long long count = 0;
        while(i <= mid and j <= right){
            if(arr[i] > arr[j]){
                count += (mid-i+1);
                temp.push_back(arr[j++]);
            }
            else{
                temp.push_back(arr[i++]);
            }
        }
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=right) temp.push_back(arr[j++]);
        for(int i=left;i<=right;i++){
            arr[i] = temp[i-left];
        }
        return count;
    }
    long long mergeSort(long long arr[], int left, int right){
        long long count = 0;
        if(left < right){
            int mid = (left + right) >> 1;
            count += mergeSort(arr,left,mid);
            count += mergeSort(arr,mid+1,right);
            count += merge(arr,left,mid,right);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        long long c = mergeSort(arr,0,n-1);
        return c;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n1, int n2, int k)
    {
        
        if(n1 > n2) return kthElement(nums2,nums1,n2,n1,k);
        int low = max(0,k-n2), high = min(n1,k);
       
        while(low<=high){
            int mid1 = (low + high) >> 1;
            int mid2 = k - mid1;
            int l1 = mid1-1 < 0 ? INT_MIN : nums1[mid1-1];
            int l2 = mid2-1 < 0 ? INT_MIN : nums2[mid2-1];
            int r1 = mid1 >= n1 ? INT_MAX : nums1[mid1];
            int r2 = mid2 >= n2 ? INT_MAX : nums2[mid2];
            if(l1 > r2){
                high = mid1-1;
            }
            else if(l2 > r1){
                low = mid1+1;
            }
            else{
                return max(l1,l2);
                
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
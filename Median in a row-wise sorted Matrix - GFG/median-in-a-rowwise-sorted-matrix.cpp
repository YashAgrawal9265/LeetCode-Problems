//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{  
public:
    int find_num_of_ele(vector<vector<int>>& mat, int ele){
        int count = 0;
        for(auto &it: mat){
            count += (upper_bound(it.begin(),it.end(),ele) - it.begin());
        }
        return count;
    }
    int median(vector<vector<int>> &mat, int r, int c){
        int low = 1, high = 1e5;
        while(high - low > 1){
            int mid = (low + high) >> 1;
            int num_of_ele = find_num_of_ele(mat,mid);
            if(num_of_ele < (r*c)/2 + 1){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        if(find_num_of_ele(mat,low) >= (r*c)/2 + 1) return low;
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
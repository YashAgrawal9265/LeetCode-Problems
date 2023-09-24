//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        vector<int> result(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i] <= st.top()) st.pop();
            if(st.empty()) result[i] = -1;
            else result[i] = st.top();
            st.push(arr[i]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
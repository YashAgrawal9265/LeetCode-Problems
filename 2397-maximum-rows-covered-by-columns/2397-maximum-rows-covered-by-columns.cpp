class Solution {
public:
    int result = INT_MAX;
    unordered_map<int,int> mp;
    void solve(vector<vector<int>>& mat, int idx, int m, int n, int k){
        if(idx == n){
            if(k == 0){
                int count = 0;
                for(auto it: mp){
                    if(it.second > 0) count++;
                }
                result = min(result,count);
            }
            return;
        }
        if(k > 0){
            for(int i=0;i<m;i++){
                if(mat[i][idx] == 1) mp[i]++;
            }
            solve(mat,idx+1,m,n,k-1);
            for(int i=0;i<m;i++){
                if(mat[i][idx] == 1) mp[i]--;
            }
            
        }
        solve(mat,idx+1,m,n,k);
       
    }
    int maximumRows(vector<vector<int>>& mat, int numSelect) {
        int m = mat.size(), n = mat[0].size();
        int k = n - numSelect;
        
        
        solve(mat,0,m,n,k);
        // cout<<result<<endl;
        return m - result;
    }
};
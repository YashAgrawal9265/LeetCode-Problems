class Solution {
public:
    int solve(vector<int>& temp, int k){
        set<int> st;
        st.insert(0);
        int prefixSum = 0;
        int mxSum = -1e8;
        for(auto i: temp){
            prefixSum += i;
            auto it = st.lower_bound(prefixSum-k);
            if(it != st.end()){
                mxSum = max(mxSum,prefixSum-(*it));
            }
            st.insert(prefixSum);
        }
        return mxSum;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int result = -1e8;
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    temp[k] += mat[j][k];
                }
                result = max(result,solve(temp,k));
            }
        }
        return result;
    }
};
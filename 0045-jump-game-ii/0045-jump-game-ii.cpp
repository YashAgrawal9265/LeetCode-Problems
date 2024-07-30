class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,1e8);
        v[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<=i+nums[i];j++){
                if(j < n ) v[j] = min(v[j],v[i]+1);
            }
        }
        // for(auto it: v) cout<<it<<" ";
        return v[n-1];
    }
};
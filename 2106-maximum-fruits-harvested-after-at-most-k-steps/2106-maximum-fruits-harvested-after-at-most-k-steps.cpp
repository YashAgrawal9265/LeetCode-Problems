class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = 2*100000 + 1;
        vector<int> prefix(n,0);
        for(auto &it: fruits){
            prefix[it[0]] = it[1];
        }
        for(int i=1;i<n;i++){
            prefix[i] += prefix[i-1];
        }
        int maxi = 0;
        // moving right;
        for(int i=startPos; i<=min(n-1,startPos + k); i++){
            int r = i;
            int x = i-startPos;
            int l = startPos - (k - 2*x);
            l = min(startPos,l);
            int temp = prefix[r];
            if(l > 0){
                temp -= prefix[l-1];
            }
            maxi = max(maxi,temp);
        }
        
        // moving left;
        for(int i=startPos; i>=max(0,startPos-k); i--){
            int l = i;
            int x = startPos - i;
            int r = startPos + (k-2*x);
            r = max(startPos,min(r,n-1));
            int temp = prefix[r];
            if(l > 0){
                temp -= prefix[l-1];
            }
            maxi = max(maxi,temp);
            
        }
        return maxi;
    }
};
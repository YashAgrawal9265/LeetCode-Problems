class Solution {
public:
    vector<int> platesBetweenCandles(string str, vector<vector<int>>& queries) {
        int n = str.size();
        vector<int> next(n,n), prev(n,n);
        if(str[n-1] == '|') next[n-1] = n-1;
        if(str[0] == '|') prev[0] = 0;
        for(int i=n-2;i>=0;i--){
            if(str[i] == '|') next[i] = i;
            else next[i] = next[i+1];
            
            if(str[n-i-1] == '|') prev[n-i-1] = n-i-1;
            else prev[n-i-1] = prev[(n-i-1)-1];
        }
        
        vector<int> prefix(n,0);
        int prev_idx = -1;
        for(int i=0;i<n;i++){
            if(str[i] == '|'){
                if(prev_idx == -1) prev_idx = i;
                else{
                    prefix[i] = (i - prev_idx - 1) + prefix[prev_idx];
                    prev_idx = i;
                }
            }
        }
        
        vector<int> result;
        
        for(auto it: queries){
            int l = next[it[0]];
            int r = prev[it[1]];
            if(l == n || r == n || l > r) result.push_back(0);
            else result.push_back(prefix[r]-prefix[l]);
        }
        return result;
        
    }
};
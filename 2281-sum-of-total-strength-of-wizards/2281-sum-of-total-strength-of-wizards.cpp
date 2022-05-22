class Solution {
public:
    int totalStrength(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<long long> prefix(n+1,0), prefix_prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + arr[i];
            prefix_prefix[i+1] = (prefix_prefix[i] + prefix[i+1]) % mod;
        }
        
        vector<int> next_smaller(n,0), prev_smaller(n,0);
        stack<int> next_st, prev_st;
        
        for(int i=0;i<n;i++){
            // calculation previous smaller 
            while(!prev_st.empty() and arr[prev_st.top()] > arr[i]){
                prev_st.pop();
            }
            if(prev_st.empty()) prev_smaller[i] = -1;
            else prev_smaller[i] = prev_st.top();
            prev_st.push(i);
            
            // calculation next smaller
            while(!next_st.empty() and arr[next_st.top()] >= arr[n-i-1]){
                next_st.pop();
            }
            if(next_st.empty()) next_smaller[n-i-1] = n;
            else next_smaller[n-i-1] = next_st.top();
            next_st.push(n-i-1);
        }
        int result = 0;
        for(int i=0;i<n;i++){
            int val = arr[i];
            int l = prev_smaller[i], r = next_smaller[i];
            int left = i - l , right = r - i;
            long long sum = 0;
            
            if(l == -1) l = 0;
            sum = (sum + 1LL*left*(prefix_prefix[(r-1)+1]-prefix_prefix[(i-1)+1])) % mod;
            sum = (sum - 1LL*right*(prefix_prefix[(i-1)+1]-prefix_prefix[(l-1)+1])) % mod;
            if(sum <= 0) sum += mod;
            
            result = (result + (1LL*val*sum)%mod) % mod;
            
        }
        return result;
        
    }
};
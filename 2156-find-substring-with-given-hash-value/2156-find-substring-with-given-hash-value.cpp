class Solution {
private:
    int val(char c){
        return c - 'a' + 1;
    }
public:
    string subStrHash(string str, int p, int mod, int k, int hashValue) {
        int n = str.size();
        long long hash = val(str[n-1]);
        int pk = 1;
        int idx = n-1;
        for(int i = n-2;i>=0;i--){
            // cout<<i<<endl;
            if(i + k >= n){
                hash = ((hash*p)%mod + val(str[i])) % mod;
                pk = (1LL*pk * p) % mod;
            }
            else{
                hash = (hash - (1LL*val(str[i+k])*pk)%mod)%mod;
                if(hash < 0) hash += mod;
                hash = (hash * p) % mod;
                hash = (hash + val(str[i])) % mod;
            }
            if(hash == hashValue){
                idx = i;
            }
        }
        
        return str.substr(idx,k);
    }
};
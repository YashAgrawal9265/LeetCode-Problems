class Solution {
public:
    void solve(int n, int k, int num, vector<int>& result){
        if(n == 0){
            result.push_back(num);
            return;
        }
        int digit = num % 10;
        if(digit + k <= 9) solve(n-1,k,num*10 + (digit+k), result);
        if(k != 0)
            if(digit - k >= 0) solve(n-1,k,num*10 + (digit-k),result);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        for(int i=1;i<=9;i++){
            solve(n-1,k,i,result);
        }
        return result;
    }
};
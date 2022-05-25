class Solution {
private:
    string base_k(long long num, int k){
        string res = "";
        while(num){
            res += (char)(num % k);
            num /= k;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    bool isPali(string str){
        int i=0;
        int j = str.size()-1;
        while(i<j){
            if(str[i] != str[j]) return false;
            i++,j--;
        }
        return true;
    }
    long long generateNum(long long num, bool odd){
        long long dupNum = num;
        if(odd) dupNum /= 10;
        
        while(dupNum){
            num = (num*10) + (dupNum % 10);
            dupNum /= 10;
        }
        return num;
    }
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        for(int i=1;n!=0;i*=10){
            // for odd length palindromes
            for(int j=i;j<i*10 && n!=0;j++){
                long long num = generateNum(j,true);
                if(isPali(base_k(num,k))){
                    n--;
                    sum += num;
                }
            }
            
            // for even length palindrome
            for(int j=i;j<i*10 && n!=0;j++){
                long long num = generateNum(j,false);
                if(isPali(base_k(num,k))){
                    n--;
                    sum += num;
                }
            }
        }
        return sum;
    }
};
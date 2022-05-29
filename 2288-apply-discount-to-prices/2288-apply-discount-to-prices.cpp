class Solution {
public:
    string solve(string str, double discount){
        
        long long x = stoll(str);
        long double t = (long double)x*discount;
        long double c = (long double)x - t;
        string temp = to_string(c);
        string result = "";
        int i;
        
        for(i=0;i<temp.size();i++){
            result += temp[i];
            if(temp[i] == '.') break;
        }
        i++;
        result += temp[i];
        i++;
        result += temp[i];
        
        return result;
    }
    string discountPrices(string str, int x) {
        double  discount = (double)x;
        discount = discount / (100.0);
        // cout<<discount<<endl;
        string result = "";
        int i=0;
        int n = str.size();
        while(i<n){
            if((i == 0 and str[i] == '$') || (i> 0 and str[i-1] == ' ' and str[i] == '$')){
                result += str[i];
                i++;
                string temp = "";
                while(i < n and str[i] >= '0' and str[i] <= '9'){
                    temp += str[i];
                    i++;
                }
                
                if((i == n || str[i] == ' ') and temp.size() > 0) result += solve(temp,discount);
                else result += temp;
                
            }
            else{
                result += str[i];
                i++;
            }
        }
        return result;
    }
};
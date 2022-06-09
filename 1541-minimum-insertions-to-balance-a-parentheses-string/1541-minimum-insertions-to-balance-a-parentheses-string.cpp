class Solution {
public:
    int minInsertions(string str) {
        int n = str.size();
        int open = 0, close = 0;
        int result = 0;
        string s;
        for(int i=0;i<n;i++){
            if(str[i] == '('){
                s = "(";
            }
            else{
                s = "))";
                if(i+1< n and str[i+1] == ')'){
                    i++;
                }
                else{
                    result += 1;
                }
            }
            if(s == "(") open++;
            else{
                if(open > 0) open--;
                else{
                    result += 1;
                }
            }
        }
        result += (open*2);
        return result;
    }
};
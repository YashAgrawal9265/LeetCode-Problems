class Solution {
public:
    int minInsertions(string str) {
        int n = str.size();
        string s;
        int open = 0, result = 0;
        for(int i=0;i<n;i++){
            if(str[i] == '('){
                s = "(";
            }
            else{
                s = "))";
                if(i + 1 < n and str[i+1] == ')'){
                    i++;
                }
                else{
                    result += 1;
                }
            }
            if(s == "("){
                open++;
            }
            else{
                if(open > 0) open--;
                else result += 1;
            }
        }
        result += (2*open);
        return result;
    }
};
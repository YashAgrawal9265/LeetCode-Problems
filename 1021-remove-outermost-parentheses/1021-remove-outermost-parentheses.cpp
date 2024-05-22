class Solution {
public:
    string removeOuterParentheses(string str) {
        int open = 0;
        string result = "";
        for(int i=0;i<str.size();i++){
            if((str[i] == '(' and open > 0) or (str[i] == ')' and open > 1)) result += str[i];
            
            if(str[i] == '(') open++;
            else if(str[i] == ')') open--;
        }
        return result;
        
    }
};
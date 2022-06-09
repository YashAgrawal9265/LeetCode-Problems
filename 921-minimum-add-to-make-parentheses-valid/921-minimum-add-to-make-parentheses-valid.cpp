class Solution {
public:
    int minAddToMakeValid(string str) {
        int n = str.size();
        int open = 0, close = 0;
        for(int i=0;i<n;i++){
            if(str[i] == '('){
                open++;
            }
            else{
                if(open > 0) open--;
                else close++;
            }
        }
        return open + close;
    }
};
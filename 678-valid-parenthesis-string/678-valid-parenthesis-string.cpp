class Solution {
public:
    bool checkValidString(string str) {
        int n = str.size();
        int openMn = 0, openMx = 0;
        for(int i=0;i<n;i++){
            if(str[i] == '('){
                openMn++, openMx++;
            }
            else if(str[i] == ')'){
                openMn--, openMx--;
            }
            else{
                openMn--;
                openMx++;
            }
            if(openMx < 0) return false;
            if(openMn < 0) openMn = 0;
        }
        if(openMn == 0) return true;
        return false;
    }
};
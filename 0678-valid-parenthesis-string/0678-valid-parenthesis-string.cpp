class Solution {
public:
    bool checkValidString(string str) {
        int n = str.size();
        int balance = 0;
        for(auto it: str){
            if(it == '(' or it == '*') balance++;
            else{
                if(balance <= 0) return false;
                balance--;
            }
        }
        if(balance == 0) return true;
        balance = 0;
        for(int i=n-1;i>=0;i--){
            if(str[i] == ')' or str[i] == '*') balance++;
            else{
                if(balance <= 0) return false;
                balance--;
            }
        }
        return true;
    }
};
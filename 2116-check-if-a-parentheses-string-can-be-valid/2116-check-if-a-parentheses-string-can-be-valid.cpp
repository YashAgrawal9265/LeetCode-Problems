class Solution {
public:
    bool canBeValid(string str, string locked) {
        int n = str.size();
        if(n&1) return false;
        int balance = 0;
        for(int i=0;i<n;i++){
            
            if(str[i] == '(' or locked[i] == '0') balance++;
            else balance--;
            if(balance < 0) return false;
        }
       
        if(balance == 0) return true;
        balance = 0;
        
        for(int i=n-1;i>=0;i--){
            if(str[i] == ')' or locked[i] == '0') balance++;
            else balance--;
            if(balance < 0) return false;
        }
        return true;
    }
};
class Solution {
public:
    string removeOuterParentheses(string str) {
        int n = str.size();
        vector<int> mp(n+1,0);
        int st = 0;
        int open = 0, close = 0;
        for(int i=0;i<n;i++){
            if(str[i] == '(') open++;
            else if(str[i] == ')') close++;
            if(open == close and open != 0 and close != 0){
                mp[st] = 1;
                mp[i] = 1;
                st = i+1;
                open = 0;
                close = 0;
            }
        }
        string result = "";
        for(int i=0;i<n;i++){
            if(mp[i] == 0) result += str[i];
        }
        return result;
    }
};
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string str = countAndSay(n-1);
        string result = "";
        int count = 1;
        for(int i=1;i<str.size();i++){
            if(str[i] != str[i-1]){
                result += to_string(count);
                result += str[i-1];
                count = 1;
            }
            else count++;
        }

        result += to_string(count);
        result += str[str.size()-1];
        return result;
    }
};
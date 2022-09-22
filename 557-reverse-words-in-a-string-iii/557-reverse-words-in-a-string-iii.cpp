class Solution {
public:
    string reverseWords(string str) {
        int n = str.size();
        string result = "";
        int prev_idx = 0;
        for(int i=0;i<n;i++){
            if(str[i] == ' '){
                string temp = str.substr(prev_idx,i-prev_idx);
                reverse(temp.begin(),temp.end());
                result += temp + ' ';
                prev_idx = i+1;
            }
        }
        string temp = str.substr(prev_idx,n-prev_idx+1);
        reverse(temp.begin(),temp.end());
        result += temp;
        return result;
    }
};
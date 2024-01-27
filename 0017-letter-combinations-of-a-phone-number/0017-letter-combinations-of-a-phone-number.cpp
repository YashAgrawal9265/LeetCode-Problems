class Solution {
    void solve(string& digits, vector<string>& letters, vector<string>& result, int idx, string temp){
        // cout<<idx<<endl;
        if(idx == digits.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<letters[digits[idx] - '0'].size();i++){
            // cout<<letters[i]<<endl;
            char c = letters[digits[idx] - '0'][i];
            solve(digits,letters,result,idx+1,temp+c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> letters = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        solve(digits,letters,result,0,"");
        return result;
    }
};
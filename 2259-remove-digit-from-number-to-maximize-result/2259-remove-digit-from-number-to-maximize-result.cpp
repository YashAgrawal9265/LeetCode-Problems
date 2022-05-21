class Solution {
public:
    string removeDigit(string str, char digit) {
        int n = str.size();
        vector<string> temp;
        for(int i=0;i<n;i++){
            if(str[i] == digit){
                temp.push_back(str.substr(0,i) + str.substr(i+1));
            }
        }
        sort(temp.begin(),temp.end(),greater<string>());
        return temp[0];
    }
};
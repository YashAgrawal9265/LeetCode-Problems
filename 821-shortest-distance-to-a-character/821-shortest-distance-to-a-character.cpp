class Solution {
public:
    vector<int> shortestToChar(string str, char c) {
        int n = str.size();
        vector<int> result(n);
        int pos = n;
        for(int i=0;i<n;i++){
            if(str[i] == c){
                pos = i;
                result[i] = 0;
            }
            else{
                result[i] = abs(i-pos);
            }
        }
        pos = 0;
        for(int i=n-1;i>=0;i--){
            if(str[i] == c){
                pos = i;
            }
            else{
                result[i] = min(result[i],abs(i-pos));
            }
        }
        return result;
    }
};
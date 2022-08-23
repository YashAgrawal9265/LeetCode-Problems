class Solution {
public:
    string shiftingLetters(string str, vector<int>& shifts) {
        int n = str.size();
        vector<int> arr(n,0);
        arr[n-1] = shifts[n-1];
        for(int i=n-2;i>=0;i--){
            arr[i] = (shifts[i] + arr[i+1]) % 26;
        }
       
        for(int i=0;i<n;i++){
            int c = (str[i] - 'a') + arr[i];
            c = c % 26;
            str[i] = c + 'a';
        }
        return str;
    }
};
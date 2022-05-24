class Solution {
public:
    string decodeCiphertext(string str, int row) {
        int n = str.size();
        int col = n / row;
        string original = "";
        for(int i=0;i<col;i++){
            for(int j=i;j<n;j+=(col+1)){
                original += str[j];
            }
        }
        while(original.back() == ' ') original.pop_back();
        return original;
    }
};
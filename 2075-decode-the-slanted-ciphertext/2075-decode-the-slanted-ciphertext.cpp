class Solution {
public:
    string decodeCiphertext(string str, int row) {
        int n = str.size();
        int col = n / row;
        vector<vector<char>> arr(row, vector<char>(col,' '));
        int k = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j] = str[k++];
            }
        }
        
        string original = "";
        
        for(int gap=0;gap<col;gap++){
            for(int i=0,j=gap;j<col&&i<row;i++,j++){
                original += arr[i][j];
            }
        }
        
        int x = original.size()-1;
        while(x >= 0){
            if(original[x] != ' ') break;
            x--;
        }
        return original.substr(0,x+1);
    }
};
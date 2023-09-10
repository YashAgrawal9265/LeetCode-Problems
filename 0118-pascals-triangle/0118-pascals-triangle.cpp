class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> ansRow;
        ansRow.push_back(1);
        int ans = 1;
        for(int col=1;col<=row;col++){
            ans *= (row-col+1);
            ans /= col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            result.push_back(generateRow(i));
        }
        return result;
    }
};
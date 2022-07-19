class Solution {
public:
    int solve(int n, int r){
        int result = 1;
        for(int i=1;i<=r;i++){
            result *= (n-r+i);
            result /= i;
        }
        return result;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(solve(i,j));
            }
            result.push_back(temp);
        }
        return result;
    }
};
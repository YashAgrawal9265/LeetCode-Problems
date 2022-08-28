class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int k=0;k<n;k++){
            int i = 0, j = k, idx = 0;
           
            vector<int> temp;
            while(i < m and j < n){
                temp.push_back(mat[i++][j++]);
            }
            sort(temp.begin(),temp.end());
            i = 0, j = k;
           
            while(i < m and j < n){
                mat[i++][j++] = temp[idx++];
            }
        }
        for(int k=1;k<m;k++){
            int j = 0, i = k, idx = 0;
            vector<int> temp;
            while(i < m and j < n){
                temp.push_back(mat[i++][j++]);
            }
            sort(temp.begin(),temp.end());
            
            j = 0, i = k;
            while(i < m and j < n){
                mat[i++][j++] = temp[idx++];
            }
        }
        return mat;
    }
};
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isSame(vector<vector<int>>& grid, int n, int r, int c){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[r][c] != grid[r+i][c+j]){
                    return false;
                }
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>>& grid, int n, int row, int col){
        if(isSame(grid,n,row,col)){
            return new Node(grid[row][col],true);
        }
        int mid = n / 2;
        Node* topLeft = solve(grid,mid,row,col);
        Node* topRight = solve(grid,mid,row,col + mid);
        Node* bottomLeft = solve(grid,mid,row+mid,col);
        Node* bottomRight = solve(grid,mid,row+mid,col+mid);
        return new Node(grid[row][col],false,topLeft,topRight,bottomLeft,bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid,n,0,0);
    }
};
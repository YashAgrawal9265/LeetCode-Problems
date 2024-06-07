class Solution {
private:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    bool isValid(vector<vector<int>>& image, vector<vector<int>>& vis, int x, int y, int m, int n, int originalColor){
        if(x >= 0 and y >= 0 and x < m and y < n and image[x][y] == originalColor and !vis[x][y]) return true;
        return false;
    }
    void solve(vector<vector<int>>& image, vector<vector<int>>& vis, int x, int y, int m, int n, int originalColor, int newColor){
        vis[x][y] = 1;
        image[x][y] = newColor;
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(isValid(image,vis,nx,ny,m,n,originalColor)){
                solve(image,vis,nx,ny,m,n,originalColor,newColor);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        int m = image.size(), n = image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int originalColor = image[sr][sc];
        solve(image,vis,sr,sc,m,n,originalColor,color);
        return image;
    }
};
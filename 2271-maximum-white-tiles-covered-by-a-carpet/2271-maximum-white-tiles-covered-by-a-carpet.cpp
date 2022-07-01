class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        sort(tiles.begin(),tiles.end());
        int cover = 0;
        int result = 0;
        int left = 0, right = 0;
        while(right < tiles.size() and left <= right){
            
            if(tiles[left][0] + len > tiles[right][1]){
                cover += (tiles[right][1]-tiles[right][0]+1);
                result = max(result,cover);
                right++;
            }
            else{
                int partial = max(0,tiles[left][0] + len - tiles[right][0]);
                result = max(result,cover+partial);
                cover -= (tiles[left][1] - tiles[left][0] + 1);
                left++;
            }
        }
        return result;
    }
};
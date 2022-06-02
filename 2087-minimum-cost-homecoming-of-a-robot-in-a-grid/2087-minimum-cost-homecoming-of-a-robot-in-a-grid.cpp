class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int stx = startPos[0], sty = startPos[1];
        int dsx = homePos[0], dsy = homePos[1];
        int result = 0;
        
        // going down
        if(dsx > stx){
            for(int row=stx+1;row<=dsx;row++){
                result += rowCosts[row];
            }
        }
        // going up
        else{
           for(int row=stx-1;row>=dsx;row--){
                result += rowCosts[row];
            } 
        }
        
        // going right
        if(dsy > sty){
            for(int col=sty+1;col<=dsy;col++){
                result += colCosts[col];
            }
        }
        // going left;
        else{
            for(int col=sty-1;col>=dsy;col--){
                result += colCosts[col];
            }
        }
        return result;
    }
};
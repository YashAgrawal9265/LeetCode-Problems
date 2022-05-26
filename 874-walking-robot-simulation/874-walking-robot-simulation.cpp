class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0;
        int mod = 4;
        set<pair<int,int>> st;
        for(auto &it: obstacles){
            int x = it[0], y = it[1];
            st.insert({x,y});
        }
        int x = 0, y = 0;
        int maxi = INT_MIN;
        for(auto &it: commands){
            if(it == -1){
                d = (d+1) % mod;
            }
            else if(it == -2){
                d = ((d-1) + mod) % mod;
            }
            else{
                int k = it;
                while(k){
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    if(st.find({nx,ny}) != st.end()){
                        break;
                    }
                    x = nx;
                    y = ny;
                    k--;
                }
                maxi = max(maxi,x*x + y*y);
            }
        }
        
        return maxi;
    }
};
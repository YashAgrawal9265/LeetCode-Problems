class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        int mod = 1e9 + 7;
        sort(hori.begin(),hori.end());
        sort(verti.begin(),verti.end());
        int mxHori = hori[0];
        for(int i=1;i<hori.size();i++){
            
            mxHori = max(mxHori,abs(hori[i]-hori[i-1]));                        
        }
        mxHori = max(mxHori,h - hori[hori.size()-1]);
        int mxVerti = verti[0];
        for(int i=1;i<verti.size();i++){
            mxVerti = max(mxVerti,abs(verti[i]-verti[i-1]));                        
        }
        mxVerti = max(mxVerti,w - verti[verti.size()-1]);
        
        return (1LL*mxHori*mxVerti) % mod;         
    }
};
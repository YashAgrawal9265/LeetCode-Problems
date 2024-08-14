class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(((start&(1<<i)) == 0 and (goal&(1<<i)) == 0) or  ((start&(1<<i)) > 0 and (goal&(1<<i)) > 0)) continue;
            cnt++;
            // cout<<((start&(1<<i)==0) and (goal&(1<<i) == 0))<<endl;
        }
        return cnt;
    }
};
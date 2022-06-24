class Solution {
public:
    
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        int mxIdx = 0;
        for(int i=0;i<target.size();i++){
            sum += target[i];
            if(target[i] > target[mxIdx]){
                mxIdx = i;
            }
        }
        long long diff = sum - target[mxIdx];
        if(target[mxIdx] == 1 || diff == 1) return true;
        if(target[mxIdx] <= diff || diff == 0 || target[mxIdx] % diff == 0) return false;
        target[mxIdx] %= diff;
        return isPossible(target);
    }
};
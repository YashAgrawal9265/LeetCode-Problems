class Solution {
public:
    bool canJump(vector<int>& arr) {
        int maxi =0 , n = arr.size();
        for(int i=0;i<n;i++){
            if(maxi < i) return false;
            maxi = max(maxi, i + arr[i]);
            
        }
        return true;
    }
};
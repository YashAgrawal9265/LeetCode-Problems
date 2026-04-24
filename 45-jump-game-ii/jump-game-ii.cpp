class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = 0, jump = 0;
        int maxi = 0;
        while(l < n-1){
            maxi = max(maxi,arr[l] + l);
            if(l == r){
                r = maxi;
                jump++;
            }
            if(r == n-1) break;
            l++;
        }
        return jump;
    }
};
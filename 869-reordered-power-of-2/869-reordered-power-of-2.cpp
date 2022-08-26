class Solution {
public:
    bool solve(int n, vector<int>& mp){
        vector<int> arr(10,0);
        while(n){
            int rem = n % 10;
            arr[rem]++;
            n /= 10;
        };
        if(arr == mp) return true;
        return false;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> mp(10,0);
        while(n){
            int rem = n % 10;
            mp[rem]++;
            n /= 10;
        };
        for(int i=0;i<31;i++){
            if(solve(1<<i,mp)) return true;
        }
        return false;
    }
};
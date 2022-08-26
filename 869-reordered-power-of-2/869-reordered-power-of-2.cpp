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
        vector<int> arr = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384,             32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216,                   33554432, 67108864, 134217728, 268435456, 536870912};
        
        vector<int> mp(10,0);
        while(n){
            int rem = n % 10;
            mp[rem]++;
            n /= 10;
        }
        
        for(int i=0;i<arr.size();i++){
            if(solve(arr[i],mp)) return true;
        }
        return false;
    }
};
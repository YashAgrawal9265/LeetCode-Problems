class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    int minimumLines(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n == 1) return 0;
        int p1 = arr[1][1] - arr[0][1];
        int p2 = arr[1][0] - arr[0][0];
        
        int d = gcd(abs(p1),abs(p2));
        int dy = p1/d;
        int dx = p2/d;
        
        int result = 1;
        for(int i=2;i<n;i++){
            p1 = arr[i][1] - arr[i-1][1];
            p2 = arr[i][0] - arr[i-1][0];
            d = gcd(abs(p1),abs(p2));
            p1 /= d, p2 /= d;
            if(p1 != dy || p2 != dx){
                dy = p1;
                dx = p2;
                result++;
            }
        }
        return result;
    }
};
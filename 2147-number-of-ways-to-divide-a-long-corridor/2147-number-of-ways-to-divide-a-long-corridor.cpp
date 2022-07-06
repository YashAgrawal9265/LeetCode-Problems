class Solution {
public:
    int numberOfWays(string str) {
        int mod = 1e9 + 7;
        int n = str.size();
        vector<int> seats;
        for(int i=0;i<n;i++){
            if(str[i] == 'S') seats.push_back(i);
        }
        if(seats.size() == 0 || seats.size() % 2) return 0;
        int result = 1;
        for(int i=2;i<seats.size();i+=2){
            result = (1LL* result * (seats[i] - seats[i-1])) % mod;
        }
        return result;
    }
};
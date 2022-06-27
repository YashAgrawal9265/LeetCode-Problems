class Solution {
public:
    int minPartitions(string str) {
        int maxi = -1;
        for(int i=0;i<str.size();i++){
            maxi = max(maxi, str[i]-'0');
        }
        return maxi;
    }
};
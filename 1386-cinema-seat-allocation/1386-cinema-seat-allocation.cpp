class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,long> mp;
        for(auto it: reservedSeats){
            int row = it[0], seat = it[1];
            mp[row] |= (1<<(10-seat));
        }
       
        int result = 0;
        for(auto it: mp){
            int count = 0;
            if(!(it.second & 480)) count++;
            if(!(it.second & 30)) count++;
            if(count == 0 and !(it.second & 120)) count++;
            result += count;
        }
       
        result += (n-mp.size())*2;
        return result;
    }
};
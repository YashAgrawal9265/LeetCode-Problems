class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fuel = 0, fuel_shortage = 0;
        int st = 0;
        for(int i=0;i<n;i++){
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                st = i + 1;
                fuel_shortage += fuel;
                fuel = 0;
            }
        }
        if(fuel + fuel_shortage >= 0) return st;
        return -1;
    }
};
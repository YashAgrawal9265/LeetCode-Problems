class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0, fuel_shortage = 0, result = 0;
        for(int i=0;i<n;i++){
            if(tank + gas[i] - cost[i] < 0){
                fuel_shortage += tank + gas[i] - cost[i];
                tank = 0;
                result = i+1;
            }
            else{
                tank += gas[i] - cost[i];
            }
            
        }
       
        if(tank + fuel_shortage >= 0) return result;
        return -1;
        
    }
};
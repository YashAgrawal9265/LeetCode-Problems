class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int steps = 0;
        int water = capacity;
        for(int i=0;i<n;i++){
            if(plants[i] <= water){
                steps++;
                water -= plants[i];
            }
            else{
                steps += (i) + (i+1);
                water = capacity - plants[i];
            }
        }
        return steps;
    }
};
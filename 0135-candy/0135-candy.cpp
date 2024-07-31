class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while(i<n){
            // considering flat surface;
            while(i<n and ratings[i] == ratings[i-1]){
                sum++;
                i++;
            }
          
            // considering upper surface of slope
            int peak = 1;
            while(i<n and ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            
            // considering lower surface of slope
            int down = 1;
            while(i<n and ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak) sum += (down-peak);
        }
        return sum;
    }
};
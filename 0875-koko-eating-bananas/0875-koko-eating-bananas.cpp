class Solution {
private: 
    int ceil(int x, int y){
        if(x%y){
            return x/y + 1;
        }
        return x/y;
    }
    bool isValid(vector<int>& piles, int mid, int h){
        int totHours = 0;
        for(auto it: piles){
            totHours += ceil(it,mid);
            if(totHours > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(isValid(piles,mid,h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(isValid(piles,low,h)) return low;
        return high;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        for(auto it: arr){
            maxi = max(maxi,it);
        }
        vector<int> buckets(maxi+1,0);
        for(auto it: arr){
            buckets[it]++;
        }

        int first = maxi, second = maxi;
        while(first > 0){
            if(buckets[first] %2 == 0){
                first--;
                continue;
            }
            int j = first-1;
            while(j >=0 and buckets[j] == 0){
                j--;
            }
            if(j <= 0) return first;
            second = j;
            buckets[second]--;
            buckets[first]--;
            buckets[first - second]++;
            first = max(second,first-second);
        }
        return 0;
    }
};
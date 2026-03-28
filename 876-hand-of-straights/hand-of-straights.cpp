class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it: arr) mp[it]++;
        for(auto it: mp){
            int ele = it.first;
            int freq = it.second;
            if(freq == 0) continue;
            while(freq--){
                for(int i=ele;i<ele+k;i++){
                    if(mp[i] == 0) return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
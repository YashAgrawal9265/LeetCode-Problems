class Solution {
public:
    bool solve(multiset<int> mst, int k, vector<int>& result){
        while(!mst.empty()){
            int lowest = *mst.begin();
            int highest = lowest + 2*k;
            if(mst.find(highest) == mst.end()) return false;
            int ele = (lowest + highest) / 2;
            result.push_back(ele);
            mst.erase(mst.begin());
            auto it = mst.find(highest);
            mst.erase(it);
        }
        return true;
    }
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        multiset<int> mst(nums.begin(),nums.end());
        
        int lowest = nums[0];
        for(int i=1;i<n;i++){
            int highest = nums[i];
            vector<int> result;
            if((highest - lowest) % 2 == 0){
                int k = (highest - lowest) / 2;
                if(k and solve(mst,k,result)){
                    return result;
                }
            }
            
        }
        return {};
    }
};
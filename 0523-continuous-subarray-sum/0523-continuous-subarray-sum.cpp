class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum % k;
            
            if(i > 0 and rem == 0) return true;
            
            if(mp.find(rem) != mp.end()){
                cout<<i-mp[rem]+1<<endl;
                if(i - mp[rem] >= 2) return true;
            }
            else mp[rem] = i;
           
        }
        return false;
    }
};
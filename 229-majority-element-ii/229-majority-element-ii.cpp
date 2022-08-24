class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = -1, cnt1 = 0, ele2 = -1, cnt2 = 0;
        for(auto it: nums){
            if(ele1 == it) cnt1++;
            else if(ele2 == it) cnt2++;
            else if(cnt1 == 0){
                ele1 = it;
                cnt1++;
            }
            else if(cnt2 == 0){
                ele2 = it;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
            
        
            
        }
        cnt1 = 0, cnt2 = 0;
        for(auto it: nums){
            if(ele1 == it) cnt1++;
            else if(ele2 == it) cnt2++;
        }
        vector<int> result;
        if(cnt1 > n/3) result.push_back(ele1);
        if(cnt2 > n/3) result.push_back(ele2);
        return result;
    }
};
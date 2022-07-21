class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int leftZero = 0, rightOne = 0;
        for(int i=0;i<n;i++) if(nums[i] == 1) rightOne++;
        int mxScore = 0;
        vector<int> result;
        for(int i=0;i<=n;i++){
            // cout<<i<<" "<<leftZero<<" "<<rightOne<<endl;
            if(leftZero + rightOne > mxScore){
                result.clear();
                result.push_back(i);
                mxScore = leftZero + rightOne;
            }
            else if(leftZero + rightOne == mxScore){
                result.push_back(i);
            }
            if(i != n){
                
                if(nums[i] == 0) leftZero++;
                else rightOne--;
                
            }
        }
        return result;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        unordered_map<int,int> mp;
        int mxLen = 0;
        while(right < fruits.size()){
            mp[fruits[right]]++;
            if(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
            mxLen = max(mxLen,right-left+1);
            right++;
        }
        return mxLen;
    }
};
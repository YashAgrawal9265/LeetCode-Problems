class Solution {
private:
    bool solve(int change, unordered_map<int,int>& mp){
        // checking for 20
        int val = change/20;
        if(mp[20] >= val){
            change = change % 20;
            mp[20] -= val;
        }
        // checking for 10
        val = change/10;
        if(mp[10] >= val){
            change = change % 10;
            mp[10] -= val;
        }
        // checking for 5
        val = change/5;
        if(mp[5] >= val){
            change = change % 5;
            mp[5] -= val;
        }
        return change == 0;
    }
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(auto it: bills){
            
            if(!solve(it-5,mp)){
                // cout<<it<<" ";
                return false;
            }
            mp[it]++;
            
        }
        return true;
    }
};
class Solution {
private:
    bool static cmp(vector<int>& a, vector<int>& b){
        if(a[0] > b[0]) return true;
        else if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return false;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
       
        vector<vector<int>> result;
        for(auto &it: arr){
            result.insert(result.begin() + it[1], it);
        }
        return result;
    }
};
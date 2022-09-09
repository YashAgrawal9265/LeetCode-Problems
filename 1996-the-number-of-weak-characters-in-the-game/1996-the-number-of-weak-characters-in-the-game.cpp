class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        int count = 0;
        int maxi = -1;
        for(auto it: arr){
            if(it[1] < maxi){
                count++;
            }
            maxi = max(maxi,it[1]);
        }
        return count;
    }
};
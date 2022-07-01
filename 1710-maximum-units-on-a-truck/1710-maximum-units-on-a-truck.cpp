class Solution {
private:
    bool static cmp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int result = 0;
        
        for(auto &it: boxTypes){
            if(truckSize >= it[0]){
                result += (it[0]*it[1]);
                truckSize -= it[0];
            }
            else{
                result += (truckSize*it[1]);
                break;
            }
        }
        return result;
    }
};
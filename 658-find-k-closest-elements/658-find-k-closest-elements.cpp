
bool cmp(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
    if(a.first < b.first) return true;
    else if(a.first == b.first){
        return a.second < b.second;
    }
    return false;
}
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<arr.size();i++){
            v.push_back({abs(arr[i]-x),{i,arr[i]}});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> result;
        for(int i=0;i<k;i++) result.push_back(v[i].second.second);
        sort(result.begin(),result.end());
        return result;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string str) {
        int n = str.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[str[i]] = i;
        }
        int end = 0, size = 0;
        vector<int> result;
        for(int i=0;i<n;i++){
            if(end < mp[str[i]]) end = mp[str[i]];
            size++;
            if(i == end){
                end = i + 1;
                result.push_back(size);
                size = 0;
            }
        }
        return result;
    }
};
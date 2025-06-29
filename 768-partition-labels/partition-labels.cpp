class Solution {
public:
    vector<int> partitionLabels(string str) {
        int n = str.size();
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++) hash[str[i]] = i;

        int end = 0, length = 0;
        vector<int> result;
        for(int i=0;i<n;i++){
            end = max(end,hash[str[i]]);
            if(i < end) length++;
            else if(i == end){
                length++;
                result.push_back(length);
                length = 0;
                end = i+1;
            }
            
        }
        return result;
    }
};
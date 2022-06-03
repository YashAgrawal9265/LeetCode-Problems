class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<pair<int,int>> even;
        int idx = 0;
        for(auto &it: digits){
            if(it % 2 == 0){
                even.push_back({it,idx});
            }
            idx++;
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(digits[i] == 0) continue;
            string temp(3,'#');
            temp[0] = digits[i] + '0';
            for(int j=0;j<even.size();j++){
                temp[2] = even[j].first + '0';
                int idx = even[j].second;
                if(idx == i) continue;
                for(int k=0;k<n;k++){
                    if(k != idx and k != i){
                        temp[1] = digits[k] + '0';
                        st.insert(stoi(temp));
                    }
                }
            }
        }
        vector<int> result(st.begin(),st.end());
        sort(result.begin(),result.end());
        return result;
    }
};
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& pass, int capacity) {
        sort(buses.begin(),buses.end());
        sort(pass.begin(),pass.end());
        unordered_set<int> st;
        int k = 0;
        int x = capacity;
        int result;
        for(int i=0;i<pass.size() and k < buses.size();){
            while(i < pass.size() and pass[i] <= buses[k] and x){
                st.insert(pass[i]);
                result = pass[i];
                x--;
                i++;
            }
            if(x > 0) result = buses[k];
            k++;
            x = capacity;
            if(i >= pass.size() and k < buses.size()) result = buses[buses.size()-1];
        }
        
        while(st.find(result) != st.end()){
            result--;
        }
        return result;
    }
};
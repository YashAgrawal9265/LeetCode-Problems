class Solution {
private:
    bool isValid(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int> st(workers.end()-mid,workers.end());
        for(int i=mid-1;i>=0;i--){
            auto it = st.end();
            it--;
            if(*it < tasks[i]){
                if(pills <= 0) return false;
                else{
                    it = st.lower_bound(tasks[i]-strength);
                    if(it == st.end()) return false;
                    pills--;
                }
            }
            st.erase(it);
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int low = 0, high = min(n,m);
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(isValid(mid,tasks,workers,pills,strength)){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        if(isValid(high,tasks,workers,pills,strength)) return high;
        return low;
    }
};
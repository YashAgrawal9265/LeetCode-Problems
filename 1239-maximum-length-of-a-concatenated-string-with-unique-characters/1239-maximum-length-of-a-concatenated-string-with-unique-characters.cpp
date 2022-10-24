class Solution {
public:
    void solve(vector<string>& arr, int idx, vector<int> freq, int& result){ 
        if(idx >= arr.size()){
            int count = 0;
            for(int i=0;i<freq.size();i++){
                if(freq[i] > 1) return;
                if(freq[i] > 0) count++;
            }
            result = max(result,count);
            return;
        }
        bool flag = true;
        for(auto it: arr[idx]){
            
            if(freq[it-'a'] > 0){
                flag = false;
                break;
            }
        }
        if(flag){
            for(auto it: arr[idx]) freq[it-'a']++;
            solve(arr,idx+1,freq,result);
            for(auto it: arr[idx]) freq[it-'a']--;
        }
        solve(arr,idx+1,freq,result);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> freq(26,0);
        int result = 0;
        solve(arr,0,freq,result);
        return result;
    }
    
};
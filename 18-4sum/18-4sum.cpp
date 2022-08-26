class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int left = j+1, right = n-1;
                long long target = k - (1LL*arr[i] + arr[j]);
                while(left < right){
                    if(arr[left] + arr[right] < target){
                        left++;
                    }
                    else if(arr[left] + arr[right] > target){
                        right--;
                    }
                    else{
                        result.push_back({arr[i],arr[j],arr[left],arr[right]});
                        left++;
                        right--;
                        while(left < n and arr[left] == arr[left-1]) left++;
                        while(right >= 0 and arr[right] == arr[right+1]) right--;
                    }
                }
                while(j+1 < n-2 and arr[j+1] == arr[j]) j++;
            }
            while(i+1<n-3 and arr[i] == arr[i+1]) i++;
        }
        return result;
    }
};
class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        int left = 0, right = n-1;
        while(left <= right){
            int minHeight = min(arr[left],arr[right]);
            int curArea = (right-left)*minHeight;
            result = max(result,curArea);
            if(arr[left] < arr[right]) left++;
            else right--;
        }
        return result;
    }
};
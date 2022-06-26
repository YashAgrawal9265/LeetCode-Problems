class Solution {
private:
    int kadane(vector<int>& arr){
        int sum = 0, maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            maxi = max(maxi,sum);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int s1 = 0, s2 = 0;
        for(int i=0;i<n;i++){
            s1 += nums1[i];
            s2 += nums2[i];
        }
        vector<int> arr1(n,0),arr2(n,0);
        for(int i=0;i<n;i++){
            arr1[i] = nums2[i] - nums1[i];
            arr2[i] = nums1[i] - nums2[i];
        }
        int first = max(s1 + kadane(arr1),s2 - kadane(arr1));
        int second = max(s1 - kadane(arr2), s2 + kadane(arr2));
        return max(first,second);
        
    }
};
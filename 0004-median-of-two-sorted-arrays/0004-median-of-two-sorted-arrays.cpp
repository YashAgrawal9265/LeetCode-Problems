class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ele1 = 0, ele2 = 0, i = 0, j = 0;
        for(int count=0;count<=(m+n)/2;count++){
            ele1 = ele2;
            if(i == m){
                ele2 = nums2[j++];
            }
            else if(j == n){
                ele2 = nums1[i++];
            }
            else if(nums1[i] < nums2[j]){
                
                ele2 = nums1[i++];
            }
            else{
                ele2 = nums2[j++];
            }
        }
        if((m+n)&1) return ele2;
        return (ele1+ele2)/2.0;
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);
        int l = 0, h = n1;
        while(l <= h){
            int m1 = (l + h) >> 1;
            int m2 = ((n1 + n2 + 1) / 2) - m1;
            int l1 = m1 - 1 < 0 ? INT_MIN : nums1[m1 - 1];
            int l2 = m2 - 1 < 0 ? INT_MIN : nums2[m2-1];
            int r1 = m1 >= n1 ? INT_MAX : nums1[m1];
            int r2 = m2 >= n2 ? INT_MAX : nums2[m2];
            if(l1 > r2){
                h = m1-1;
            }
            else if(l2 > r1){
                l = m1 + 1;
            }
            else{
                if((n1+n2)&1) return max(l1,l2)/1.0;
                else return (max(l1,l2) + min(r1,r2)) / 2.0;
            }
        }
        return 1.0;
        

    // int n1 = nums1.size(), n2 = nums2.size();
    //     if(n1 > n2) return findMedianSortedArrays(nums2,nums1);
    //     int l = 0, h = n1;
    //     while(l <= h){
    //         int m1 = (l + h) >> 1;
    //         int m2 = (n1 + n2)/2 - m1;
    //         int l1 = m1 - 1 < 0 ? INT_MIN : nums1[m1-1];
    //         int l2 = m2 - 1 < 0 ? INT_MIN : nums2[m2-1];
    //         int r1 = m1 == n1 ? INT_MAX : nums1[m1];
    //         int r2 = m2 == n2 ? INT_MAX : nums2[m2];
    //         if(l1 > r2){
    //             h = m1 - 1;
    //         }
    //         else if(l2 > r1){
    //             l = m1 + 1;
    //         }
    //         else{
    //             if((n1+n2)&1) return min(r1,r2);
    //             return (max(l1,l2) + min(r1,r2)) / 2.0;
    //         }
    //     }
    //     return 1.0;

    }
};
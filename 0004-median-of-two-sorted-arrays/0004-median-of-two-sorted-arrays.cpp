class Solution {
public:
    inline int getMinAndIncrement(
        int &ptr1, int &ptr2, 
        vector<int>& nums1, vector<int>& nums2) {
        if(ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if(nums1[ptr1] < nums2[ptr2])
                return nums1[ptr1++];
            return nums2[ptr2++];
        } else if (ptr1 < nums1.size()) {
            return nums1[ptr1++];
        } else {
            return nums2[ptr2++];
        }   
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        bool isOdd = (m + n) % 2;
        int p1 = 0, p2 = 0;
        int medianCount = isOdd ? (m+n)/2 : ((m+n)/2-1);
        while(medianCount) {
            getMinAndIncrement(p1, p2, nums1, nums2);
            medianCount--;
        }
        if(isOdd)
            return getMinAndIncrement(p1, p2, nums1, nums2);
        return ((double)getMinAndIncrement(p1, p2, nums1, nums2) + (double)getMinAndIncrement(p1, p2, nums1, nums2)) / 2;
    }
};
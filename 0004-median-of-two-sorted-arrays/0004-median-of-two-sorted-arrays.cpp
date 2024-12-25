class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // median 
        int N1 = nums1.size(), N2 = nums2.size();
        if (N1 > N2) {
            swap(N1, N2);
            swap(nums1, nums2);
        }
        
        int TN = N1 + N2;
        
        int left = 0, right = N1;
        
        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = (TN + 1) / 2 - partitionX;
            
            int maxL1, minR1, maxL2, minR2; 
            maxL1 = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
            minR1 = (partitionX == N1) ? INT_MAX : nums1[partitionX];
            
            maxL2 = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
            minR2 = (partitionY == N2) ? INT_MAX : nums2[partitionY];
            
            if (maxL1 <= minR2 && maxL2 <= minR1) {
                if (TN % 2 == 0) {
                    return (
                        max(maxL1, maxL2) + min(minR1, minR2)
                    )/2.0;
                } else {
                    return max(maxL1, maxL2);
                }
            } else if (maxL1 > minR2) {
                right = partitionX - 1;
            } else {
                left = partitionX + 1;
            }
        }
        return 0.0;
    }
};
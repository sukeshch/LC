class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*vector<int> result;
        int counter1 = 0, counter2 = 0;
        while(counter1 < m && counter2 < n)
        {
            if(nums1[counter1] < nums2[counter2]){
                result.push_back(nums1[counter1]);
                counter1++;
            } else {
                result.push_back(nums2[counter2]);
                counter2++;
            }
        }
        while(counter1 < m)
        {
            result.push_back(nums1[counter1++]);
        }
        while(counter2 < n)
        {
            result.push_back(nums2[counter2++]);
        }
        nums1 = result; */
        
        int counter = m+n-1, l = m-1, r = n-1;
        while(counter >= 0) {
            if(l >= 0 && r >= 0)
            {
                if(nums1[l] > nums2[r]){
                    nums1[counter] = nums1[l];
                    l--;
                }
                else {
                    nums1[counter] = nums2[r];
                    r--;
                }
            } else if(l >= 0) {
                nums1[counter] = nums1[l];
                l--;
            } else if (r >= 0) {
                nums1[counter] = nums2[r];
                r--;
            }
            counter--;
        }
    }
};
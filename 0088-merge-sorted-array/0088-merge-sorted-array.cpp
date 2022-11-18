class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
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
        nums1 = result;
    }
};
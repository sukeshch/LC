class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n2_map;
        stack<int> st;
        
        for(int i = 0; i < nums2.size(); i++) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                n2_map[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> result(nums1.size(), -1);
        for(int idx = 0; idx < nums1.size(); idx++) {
            if(n2_map.count(nums1[idx]) != 0)
                result[idx] = n2_map[nums1[idx]];
        }
        return result;
    }
};
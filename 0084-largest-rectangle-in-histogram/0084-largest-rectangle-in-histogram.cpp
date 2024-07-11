class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st; 
        st.push(-1);
        
        for (int idx = 0; idx < heights.size(); idx++) {
            while (st.top() != -1 && heights[st.top()] >= heights[idx]) {
                // where to update result
                int cur_ht = heights[st.top()];
                st.pop();
                result = max(result, 
                             cur_ht * (idx - st.top() - 1));
            }
            st.push(idx);
        }
        int sz = heights.size();
        while (st.top() != -1) {
            // where to update result
            int cur_ht = heights[st.top()];
            st.pop();
            result = max(
                result, 
                cur_ht * (sz - st.top() - 1));
        }
        
        return result;
    }
};
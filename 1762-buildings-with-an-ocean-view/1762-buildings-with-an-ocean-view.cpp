class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> st;
        // st.push(0);
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && heights[st.top()] <= heights[i]) {
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> result(st.size(), 0);
        for(int i=0; i<result.size(); i++) {
            result[result.size() - 1 - i] = st.top();
            st.pop();
        }
        return result;
    }
};
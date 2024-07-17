class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> st(heights.size(), 0);
        int st_sz = 0;
        for(int i=0; i<heights.size(); i++) {
            while(st_sz > 0 && heights[st[st_sz-1]] <= heights[i]) {
                st_sz--;
            }
            st[st_sz++] = i;
        }
        
        // vector<int> result(st.size(), 0);
        // for(int i=0; i<result.size(); i++) {
        //     result[result.size() - 1 - i] = st.top();
        //     st.pop();
        // }
        st.resize(st_sz);
        return st;
    }
};
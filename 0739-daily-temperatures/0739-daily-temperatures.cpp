class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> st;
        st.push(0);
        for(int i=1; i<T.size(); i++) {
            while(!st.empty() && T[st.top()] < T[i]) {
                res[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
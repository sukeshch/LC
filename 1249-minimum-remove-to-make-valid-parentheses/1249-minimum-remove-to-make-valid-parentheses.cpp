class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        stack<int> st;
        int idx = 0;
        while(idx < s.size()) {
            if(s[idx] == '(' || s[idx] == ')') {
                if(s[idx] == ')' && !st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(idx);
                }
            }
            idx++;
        }
        
        for(int i=s.size()-1; i >= 0; i--) {
            if(!st.empty() && st.top() == i) {
                st.pop();
            } else {
                result += s[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
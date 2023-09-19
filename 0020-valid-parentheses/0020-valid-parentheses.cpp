class Solution {
public:
    
    
    bool isValid(string s) {
        string st;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[')
                st += c;
            else {
                if (st.size() == 0) {
                    return false;
                }
                char matching_char;
                if(c == ')') matching_char = '(';
                if(c == ']') matching_char = '[';
                if(c == '}') matching_char = '{';
                
                if (matching_char != st.back()) {
                    return false;
                }
                st.pop_back();
            }
        }
        return st.empty();
    }
};
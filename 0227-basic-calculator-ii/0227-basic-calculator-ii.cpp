class Solution {
public:
    int getNum(string &s, int &idx) {
        int mult = 1;
        while(!isdigit(s[idx])) {
            if(s[idx]=='-')
                mult = -1;
            idx++;
        }
        
        int res = 0;
        while(idx < s.size() && isdigit(s[idx])) {
            res = 10 * res + (s[idx]-'0');
            idx++;
        }
        return res * mult;
    }
    
    int calculate(string s) {
        stack<string> st;
        int idx = 0;
        while(idx < s.size()) {
            if(s[idx] == ' ') 
                idx++;
            else if(s[idx] == '*' || s[idx] == '/') {
                bool is_mult = (s[idx] == '*');
                auto second = getNum(s, idx);
                auto first = stoi(st.top());
                st.pop();
                st.push(to_string(
                    is_mult ? 
                    first * second : 
                    int(first / second) 
                ));
            } else if(isdigit(s[idx])) {
                st.push(to_string(getNum(s, idx)));
            } else {
                st.push(to_string(getNum(s,idx)));
            }
        }
        int res = 0;
        while(!st.empty()) {
            res += stoi(st.top());
            st.pop();
        }
        return res;
    }
};
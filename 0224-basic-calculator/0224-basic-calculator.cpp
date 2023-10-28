class Solution {
    stack<pair<int,int>> exp_st_;
    stack<string> st;
public:
    
    string getInt(string &input, int &idx) {
        int res = 0;
        bool isnegative = 0;
        if(input[idx] == '-') {
            idx++;
            isnegative = true;
        }
        while(idx < input.size() && isdigit(input[idx])) {
            res = 10*res + (input[idx]-'0');
            idx++;
        }
        res *= (isnegative ? -1 : 1);
        return to_string(res);
    }
    
    int calculate(string input) {
        for (int idx = 0; idx < input.size(); ) {
            if(input[idx] == ' ')
                idx++;
            if(input[idx] == ')') {
                // continue - should I pop until last '(' and then evaluate?
                // or running evaluation --> optimization
                int curr = 0;
                while(!st.empty() && st.top() != "(") {
                    if (st.top() == "+") {
                        st.pop();
                    } else if (st.top() == "-") {
                        st.pop();
                    } else { // number
                        auto t = stoi(st.top());
                        st.pop();
                        if(!st.empty()) {
                            curr += t * ((st.top() == "-") ? -1 : 1);
                        }
                    }
                }
                st.pop();
                st.push(to_string(curr));
                idx++;
            } else if(input[idx] == '(') {
                st.push("(");
                idx++;
            } else if(input[idx] == '+') {
                st.push("+"); // as + can only be a operation not a symbol
                idx++;
            } else if(input[idx] == '-') {
                // idx + 1 < input.size() - not needed as its guaranteed
                if(!isdigit(input[idx+1])) { // -12
                    st.push("-");
                    idx++;
                } else { 
                    // same as digit
                    st.push(getInt(input, idx));
                }
            } else { // if digit
                st.push(getInt(input, idx));
            }
        }
        int res = 0;
        while(!st.empty()) {
            if(st.top() == "+" || st.top() == "-") {
                st.pop();
            } else {
                int curr = stoi(st.top());
                st.pop();
                res += curr * (!st.empty() && st.top() == "-" ? -1 : 1);
            }
        }
        return res;
    }
    
    /*
    int calculate(string input) {
        int idx = 0;
        stack<int> brackets_st;
        
        while(idx < input.size()) {
            if(input[idx] == '(') {
                brackets_st.push(idx);
            } else if (input[idx] == ')') {
                auto t = brackets_st.top();
                brackets_st.pop();
                
                exp_st_.push({t, idx});
            }
        }
        
        int result = 0;
        while(!exp_st_.empty()) {
            auto [s,t] = exp_st_.top();
            exp_st_.pop();
            
        }
        return result;
    } 
    */
};
class Solution {
public:
    string makeGood(string s) {
        int current = 0;
        if (s.size() <= 1) return s;
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++)
        {
            if(!st.empty() &&  
               ((int(st.top()-'a') == int(s[i]-'A')) ||
                (int(st.top()-'A') == int(s[i]-'a'))) )
            {
                st.pop();
            }
            else st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
            
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int idx = 0;
        while(idx < s.size()) {
            if(s[idx] == ' ') {
                idx++;
                continue;
            }
            
            int start = idx;
            int end = start;
            while(idx < s.size() && s[idx] != ' ') {
                end = idx;
                idx++;
            }
            reverse(s.begin() + start, s.begin() + end + 1);
        }
        
        return s;
    }
};
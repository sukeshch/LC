class Solution {
public:
    inline bool is_pal(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        if(s.size() <= 2) return true;
        
        int start = 0, end = s.size()-1;
        int d_count = 0;
        
        while(start < end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            }
            else {
                return is_pal(s, start, end-1) || is_pal(s, start+1, end);
            }
        }
        return true;
    }
};
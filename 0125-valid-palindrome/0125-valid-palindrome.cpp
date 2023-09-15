class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, end = s.size() - 1;
        while(st <= end) {
            if(!isdigit(s[st]) && !isalpha(s[st])){
                st++;
                continue;
            }
            if(!isdigit(s[end]) && !isalpha(s[end])) {
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])) 
                return false;
                
            st++;
            end--;
        }
        return (st > end);
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int counts[255]{0};
        
        int start = 0;
        for(int i=0; i<s.size(); i++) {
            if(start<=i && counts[s[i]] > 0) {
                while(counts[s[i]] != 0) {
                    counts[s[start++]]--;
                }
            }
            max_len = max(max_len, i-start+1);
            counts[s[i]]++;
        }
        
        return max_len;
    }
};
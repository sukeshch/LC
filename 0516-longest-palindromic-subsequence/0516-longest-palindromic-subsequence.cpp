class Solution {
public:
    vector<vector<int>> dp;
    int recurse(string &s, int st, int end) {
        if(dp[st][end] != -1) return dp[st][end];
        if(st == end) return 1;
        if(st > end) return 0;
        int res;
        if(s[st] == s[end]) {
            res =  2 + recurse(s, st+1, end-1);
        } else {
            res = max(
                recurse(s, st, end-1), 
                recurse(s, st+1, end) 
                      );
        }
        return dp[st][end] = res;
    }
    
    int longestPalindromeSubseq(string s) {
        dp = std::vector<vector<int>>(1001, std::vector<int>(1001, -1));
        return recurse(s, 0, s.size()-1);
    }
};
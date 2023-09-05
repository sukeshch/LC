class Solution {
public:
//     vector<vector<int>> dp;
//     int recurse(string &s, int st, int end) {
//         if(dp[st][end] != -1) return dp[st][end];
//         if(st == end) return 1;
//         if(st > end) return 0;
//         int res;
//         if(s[st] == s[end]) {
//             res =  2 + recurse(s, st+1, end-1);
//         } else {
//             res = max(
//                 recurse(s, st, end-1), 
//                 recurse(s, st+1, end) 
//                       );
//         }
//         return dp[st][end] = res;
//     }
    
//     int longestPalindromeSubseq(string s) {
//         dp = std::vector<vector<int>>(1001, std::vector<int>(1001, -1));
//         return recurse(s, 0, s.size()-1);
//     }
    
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001] = {0};
        for(int j=0; j < s.size(); j++) {
            dp[j][j] = 0;
            dp[j][j+1] = 1;
        }
        dp[s.size()][s.size()] = 0;
        
        for(int len = 2; len <= s.size(); len++) {
            for(int j = 0; j + len <= s.size(); j++) {
                if(s[j] == s[j+len-1]) {
                    dp[j][j + len] = dp[j+1][j+len-1] + 2;
                } else {
                    dp[j][j + len] = max(dp[j][j + len - 1], dp[j + 1][j + len]);
                }
            }
        }
        return dp[0][s.size()];
    }
};
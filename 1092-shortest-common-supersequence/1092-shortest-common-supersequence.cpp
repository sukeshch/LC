class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        // find LCS first 
        // backtrack to find common string
        // add remaining strings from str1, str2
        int dp[1001][1001] = {};
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                if(a[i] == b[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        // dp[a.size()][b.size()] contains length of LCS
        // backtrack to find the common string
        // cout << "LCS length : " << dp[a.size()][b.size()] << endl;
        int m = a.size(), n = b.size();
        string common = "";
        while(m && n) { // m > 0 && n > 0
            if(dp[m][n] == dp[m-1][n]) {
                common += a[--m];
            } else if (dp[m][n] == dp[m][n-1]) {
                common += b[--n];  
            } else {
                --m;
                --n;
                common += a[m];
            }
        }
        // common is stored as reverse
        // cout << "common str " << common << endl;
        return a.substr(0, m) + b.substr(0, n) + string(common.rbegin(), common.rend());
    }
};
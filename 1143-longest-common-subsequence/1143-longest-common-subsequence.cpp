class Solution {
public:
    vector<vector<int>> dp;
    int recurse(string &text1, string &text2, int id1, int id2) {
        if(id1 >= text1.size() || id2 >= text2.size()) {
            return 0;
        }
        if(dp[id1][id2] != -1) {
            // cout << "memo found \n";
            return dp[id1][id2];
        }
        int length = -1; // max
        if(text1[id1] == text2[id2]) {
            length = max(length,  
                        1 + recurse(text1, text2, id1 + 1, id2 + 1)
                        );
        } else {
            // not matching text2[i]
            length = max(length,  
                            recurse(text1, text2, id1, id2 + 1));
            length = max(length,  
                            recurse(text1, text2, id1+1, id2));
            
        }
        return dp[id1][id2] = length;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        if(text1 == text2) return text1.size();
        if(text1 == "" || text2 == "") return 0;
        dp = std::vector<std::vector<int>>(
                    text1.size(), std::vector<int>(text2.size(), -1));
        return recurse(text1, text2, 0, 0);
    }
};
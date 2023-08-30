class Solution {
public:
    bool recurse(int m, int d, int score, bitset<21> taken, unordered_map<ulong, bool> &dp) {
        if(dp.count(taken.to_ulong()) != 0) {
            return dp[taken.to_ulong()];
        }
        for(int i=0; i < m; i++) {
            if(!taken.test(i)) {
                taken.set(i);
                
                bool res = ((score + i+1) >= d) || (!recurse(m, d, score + i+1, taken, dp));
                taken.reset(i);
                
                if(res) return dp[taken.to_ulong()] = true;
            }
        }
        return dp[taken.to_ulong()] = false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((maxChoosableInteger*(maxChoosableInteger+1))/2 < desiredTotal) return false;
        bitset<21> taken(0);
        unordered_map<ulong, bool> dp;
        return recurse(maxChoosableInteger, desiredTotal, 0, taken, dp);
    }
};
class Solution {
public:
    int MOD=1000000007;
    vector<vector<int>> dp;
    int recurse(long long p, long long d) {
        if(p == 0 && d == 0) {
            return 1;
        }
        if(dp[p][d] != -1) {
            return dp[p][d];
        }
        long long count = 0;
        if(p > 0) {
            count += (p * recurse(p-1, d)) % MOD;
        }
        if(d > p) {
            count += ((d-p) * recurse(p, d-1) % MOD) % MOD;
        }
        
        return dp[p][d] = count % MOD;
    }
    // " " --> "P" --> "D"
    int countOrders(int n) {
        int pickup = n, delv = n;
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return recurse(n, n) % MOD;
    }
    
    /*
    string end_state;
    unordered_map<string, int> dp;
    int recurse(string taken) {
        if(taken == end_state)
            return 1;
        if(dp.count(taken) != 0) 
            return dp[taken];
        
        long long count = 0;
        for(int i=0; i<taken.size(); i++) {
            if(taken[i] == ' ') {
                taken[i] = 'P';
                count += recurse(taken);
                taken[i] = ' ';
            } else if (taken[i] == 'P') {
                taken[i] = 'D';
                count += recurse(taken);
                taken[i] = 'P';
            }
            count %= MOD;
        }
        return dp[taken] = count % MOD;
    }
    // " " --> "P" --> "D"
    int countOrders(int n) {
        string taken(n, ' ');
        end_state = string(n, 'D');
        return recurse(taken);
    } */
};
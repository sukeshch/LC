class Solution {
public:
    vector<int> dp;
    int N;
    int recurse(vector<vector<int>>& pairs, int cur_index) {
        if(cur_index >= N) {
            return 0;
        }
        if(dp[cur_index] != -1) return dp[cur_index];
        
        int nxt_nonoverlap_idx = cur_index+1;
        int st = pairs[cur_index][0], end = pairs[cur_index][1];
        
        while(nxt_nonoverlap_idx < N && end >= pairs[nxt_nonoverlap_idx][0]) {
            nxt_nonoverlap_idx++;
        }
        
        int longest_chain = max(
            recurse(pairs, cur_index+1), 
            1 + recurse(pairs, nxt_nonoverlap_idx));
        
        return dp[cur_index] = longest_chain;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        N = pairs.size();
        for(int i = 0; i < N; i++) { // scale to 0-2000
            pairs[i][0] += 1000;
            pairs[i][1] += 1000;
        }
        sort(pairs.begin(), pairs.end());
        dp = vector<int>(pairs.size()+1, -1);
        return recurse(pairs, 0);
    }
};
class Solution {
public:
    int M, N;
    vector<short> count0, count1;
    vector<vector<vector<optional<short>>>> dp;
    
    int recurse(vector<string>& input, int idx, int cM, int cN) {
        if(idx == input.size()) {
            dp[idx][cM][cN] = 0;
            return 0;
        }
        if(dp[idx][cM][cN] != nullopt) {
            return dp[idx][cM][cN].value();
        }
        int res = 0;
        // picked
        if ( cM + count0[idx] <= M && cN + count1[idx] <= N ) {
            // cout << "picked " << idx << endl;
            res = max(
                res, 
                1 + recurse(input, idx+1, cM + count0[idx], cN + count1[idx])
            ); 
        }
        // not picked case
        if (cM <= M && cN <= N) {
            // cout << "not picked " << idx << endl;
            res = max(res, recurse(input, idx+1, cM, cN));
        }
        dp[idx][cM][cN] = res;
        return dp[idx][cM][cN].value();
    }
    
    int findMaxForm(vector<string>& input, int m, int n) {
        M = m;
        N = n;
        count0.resize(input.size()+1, 0);
        count1.resize(input.size()+1, 0);
        // pre calculate zeros and ones count
        for(int i=0; i<input.size(); i++) {
            int ct_zeros = 0;
            for(auto c : input[i]) {
                if(c == '0') ct_zeros++;
            }
            count0[i] = ct_zeros;
            count1[i] = input[i].size() - ct_zeros;
            // cout << "i : 0s " << count0[i] << " 1s: " << count1[i] << endl;
        }
        dp = vector<vector<vector<optional<short>>>>(
            input.size() + 1,
            vector<vector<optional<short>>>(M + 1, vector<optional<short>>(N+1, nullopt)));
        return recurse(input, 0, 0, 0);
    }
};
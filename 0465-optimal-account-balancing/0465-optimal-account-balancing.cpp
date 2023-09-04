class Solution {
public:
    int findMinTransfers(int n, int N, 
                         vector<int> &C) {
        while(n < N && C[n] == 0) {
            n++;
        }
        if(n == N) {
            return 0;
        }
        int ret = N; // max value
        for(int i = n+1; i < N; i++) {
            if(C[i] * C[n] < 0) {
                C[i] = C[i] + C[n];
                ret = min(ret, 
                         1 + findMinTransfers(n+1, N, C)
                         );
                C[i] = C[i] - C[n];
            }
        }
        return ret;
    }
    
    int minTransfers(vector<vector<int>>& transactions) {
        int net[12] = {0};
        for(auto t : transactions) {
            net[t[0]] += t[2];
            net[t[1]] -= t[2];
        }
        vector<int> credit_list;
        for(int i=0; i<12; i++) {
            if(net[i] != 0)
                credit_list.push_back(net[i]);
        }
        int N = credit_list.size(); 
        
        return findMinTransfers(0, N, credit_list);
    }
};
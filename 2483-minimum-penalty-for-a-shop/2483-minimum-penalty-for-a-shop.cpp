class Solution {
public:
    int bestClosingTime(string customers) {
        int N = customers.size();
        vector<bool> is_customer(N, false);
        for(int i=0; i<N; i++) {
            if(customers[i] == 'Y') 
                is_customer[i] = true;
        }
        
        vector<int> penalty_open(N+2,0);
        vector<int> penalty_close(N+2,0);
        
        int res_ind = -1, min_penalty = INT_MAX;
        penalty_open[0] = 0;
        for ( int i = 0; i < N; i++ ) {
            penalty_open[i + 1] = penalty_open[i] + (is_customer[i] ? 0 : 1);
        }
        penalty_close[N+1] = 0;
        for ( int i = N-1; i >= 0; i--) {
            penalty_close[i+1] = penalty_close[i+1+1] + (is_customer[i] ? 1 : 0);
        }
        
        for(int i=0; i<=N; i++) {
            if(min_penalty > (penalty_open[i] + penalty_close[i+1]))  {
                min_penalty = penalty_open[i] + penalty_close[i+1];
                res_ind = i;
            }
        }
        
        return res_ind;
    }
};
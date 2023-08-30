class Solution {
public:
    int bestClosingTime(string customers) {
        int N = customers.size();
        vector<bool> is_customer(N, false);
        int total_penalty = 0;
        for(int i=0; i<N; i++) {
            if(customers[i] == 'Y')  {
                is_customer[i] = true;
                total_penalty++;
            }
        }
        int res_ind = 0, min_penalty = total_penalty;
        int cur_penalty = total_penalty;
        
        for ( int i = 0; i < N; i++ ) {
            
            cur_penalty += is_customer[i] ? -1 : 1;
                
            if(cur_penalty < min_penalty) {
                res_ind = i+1;
                min_penalty = cur_penalty;
            }
        }
        
        return res_ind;
    }
};
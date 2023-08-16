class Solution {
public:
    double minmaxGasDist(vector<int>& st, int k) {
        double low = 0, high = st.back()-st[0];
        double res = high;
        while(low + 1.0/1000000 < high) {
            double mid = (low + high) / 2.0;
            
            int st_needed = 0;
            for(int i=1; i<st.size(); i++) {
                st_needed += ceil((st[i] - st[i-1]) / mid) - 1 ;
            }
            
            if(st_needed <= k) {
                high = mid;
                res = mid;
            }
            else {
                low = mid;
            }
        }       
        return res;
    }
};
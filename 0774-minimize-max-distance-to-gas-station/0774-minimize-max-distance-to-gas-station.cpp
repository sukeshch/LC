class Solution {
public:
    // This fails without inline function. 
    // showing why inline functions are faster!
    bool possible(vector<int>& stations, double k, double d) {
        int st_needed = 0;
        for(int i=1; i<stations.size(); i++) {
            st_needed += ceil((stations[i] - stations[i-1]) / d) - 1 ;
        }
        return st_needed <= k;
    }
    
    double minmaxGasDist(vector<int>& st, int k) {
        double low = 0, high = st.back()-st[0];
        double res = high;
        while(low + 1.0/1000000 < high) {
            double mid = (low + high) / 2.0;
            if(possible(st, k, mid)) {
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
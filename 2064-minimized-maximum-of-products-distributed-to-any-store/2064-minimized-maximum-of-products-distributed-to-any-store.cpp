class Solution {
public:
    bool canProductsDist(vector<int>& q, int st, int mq) {
        int idx = 0;
        while(st > 0 && idx < q.size() ) {
            st -= ceil(1.0 * q[idx] / mq);
            if(st < 0) return false;
            idx++;
        }
        if(idx == q.size()) return true;
        return false;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        // std::sort(quantities.begin(), quantities.end(), std::greater<int>());
        int max_qty = *max_element(quantities.begin(), quantities.end());
        int low = 1, high = max_qty;
        
        int res = high;
        int mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(canProductsDist(quantities, n, mid)) { // satisfies, so search low, mid space
                high = mid - 1;
                res = mid;
            } else { // not satisfied
                low = mid + 1;
            }   
        }
        return res;
    }
};
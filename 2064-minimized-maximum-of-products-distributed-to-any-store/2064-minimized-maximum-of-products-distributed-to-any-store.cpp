class Solution {
public:
    bool canProductsDist(vector<int>& q, int st, int mq) {
        int idx = 0;
        while(st > 0 && idx < q.size() ) {
            // cout << " v " << ceil(1.0 * q[idx] / mq) << endl;
            st -= ceil(1.0 * q[idx] / mq);
            
            if(st < 0) return false;
            idx++;
        }
        if(idx == q.size()) return true;
        return false;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        std::sort(quantities.begin(), quantities.end(), std::greater<int>());
        int max_qty = *max_element(quantities.begin(), quantities.end());
        int low = 1, high = max_qty;
        
        int res = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            // std::cout << "mid " << mid ;
            if(canProductsDist(quantities, n, mid)) { // satisfies, so search low, mid space
                // cout << " s " << endl;
                high = mid - 1;
                res = mid;
            } else { // not satisfied
                // cout << " ns " << endl;
                low = mid + 1;
            }   
        }
        return res;
    }
};
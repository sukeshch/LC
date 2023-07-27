class Solution {
public:
    int recurse(vector<int>& cookies, int index, vector<int> &distribute, int zero_count) {
        if(zero_count > cookies.size() - index)
            return INT_MAX;
        
        if(index == cookies.size()) {
            return *max_element(distribute.begin(), distribute.end());
        }
        int minv = INT_MAX;
        for(int i=0; i<distribute.size(); i++) {
            if(!distribute[i]) zero_count--;
            distribute[i] += cookies[index];
            minv = min(minv, recurse(cookies, index + 1, distribute, zero_count));
            distribute[i] -= cookies[index];
            if(!distribute[i]) zero_count++;
        }
        return minv;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);
        int zero_count = k;
        return recurse(cookies, 0, distribute, zero_count);
    }
};
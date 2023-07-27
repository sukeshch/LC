class Solution {
public:
    int recurse(vector<int>& cookies, int index, vector<int> &distribute) {
        if(index == cookies.size()) {
            return *max_element(distribute.begin(), distribute.end());
        }
        int minv = INT_MAX;
        for(int i=0; i<distribute.size(); i++) {
            distribute[i] += cookies[index];
            minv = min(minv, recurse(cookies, index + 1, distribute));
            distribute[i] -= cookies[index];
        }
        return minv;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);
        
        return recurse(cookies, 0, distribute);
    }
};
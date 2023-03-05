class Solution {
public:
    int recurse(int n) {
        if(n < 0) return 0;
        if(n==0)
            return 1;
        return recurse(n-1) + recurse(n-2);
    }
    
    int climbStairs(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 1;
        for(int i = 2; i <= n; i++) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }
};
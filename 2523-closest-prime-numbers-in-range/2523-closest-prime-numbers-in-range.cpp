class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        bool isPrime[1000001]{};
        int curr = 2;
        for(int i=2; i<=right; i++) {
            isPrime[i] = true;
        }
        
        while(curr * curr <= right) {
            if(isPrime[curr]) {
                int sieve = 2 * curr;
                while(sieve <= right) {
                    isPrime[sieve] = false;
                    sieve += curr;
                } 
            }
            curr++;
        }
        
        int resDiff = INT_MAX;
        vector<int> res{-1,-1};
        curr = left;
        int prev = -1;
        while(curr <= right) {
            if(isPrime[curr]) {
                if(resDiff > (curr - prev)) {
                    if(prev != -1) 
                        resDiff = (curr - prev);
                    res[0] = prev;
                    res[1] = curr;
                }
                prev = curr;
                if(resDiff < 3) break;
            }
            
            curr++;
        }
        if(res[0] == -1) return {-1,-1};
        return res;
    }
};
class Solution {
public:
    string countAndSay(int n) {
        string res = "1", current = "";
        if(n==1) {
            return res;
        }
        
        for(int k = 1; k < n; k++) {
            int ct = 1, prev = res[0];
            {
                for(int i=1; i < res.size(); i++) {
                    if(prev == res[i]) {
                        ct++;
                    } else {
                        current += prev;
                        current += char(ct + '0');
                        ct = 1;
                        prev = res[i];
                    }
                }
                // handle the last digit or case
                current += prev;
                current += char(ct + '0');
            }
            res = current;   // store result in current
            current = "";    // reset current
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
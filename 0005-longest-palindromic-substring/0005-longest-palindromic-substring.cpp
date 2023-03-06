class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> isPal(s.size(), vector<bool>(s.size()));
        int resL = 0, resR = 0;
        for(int i=0; i<s.size(); i++) {
            isPal[i][i] = true;
        }

        for(int i = 1; i<s.size(); i++) 
        {
            if(s[i] == s[i-1])
            {
                isPal[i][i-1] = isPal[i-1][i] = true;
                resL = i-1;
                resR = i;
                cout << "11\n";
            }
        }
        
        for(int len = 2; len <= s.size(); len++) {
            // bool updated = false;
            for(int i=len; i<s.size(); i++) {
                if( isPal[i-1][i-len+1] && s[i] == s[i-len]) {
                    isPal[i][i-len] = true;
                    resL = i-len;
                    resR = i;
                    // updated = true;
                    // cout << "jere " << resL << " " << resR << endl;
                } else isPal[i][i-len] = false;
            }
            // if(!updated) return s.substr(resL, resR-resL+1);
        }
        // cout << "ret\n";
        return s.substr(resL, resR-resL+1);
    }
};
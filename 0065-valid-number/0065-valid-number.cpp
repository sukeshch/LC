class Solution {
public:
    bool checkExponent(string &s, int &idx) {
        // check for exponent
        if (idx < s.size() && s[idx] == 'e' || s[idx] == 'E')  {
            idx++;
            // check sign
            if (idx < s.size() && s[idx] == '+' || s[idx] == '-') {
                idx++;
            }
            // must have digit
            if(idx < s.size() && isdigit(s[idx])) {
                while(idx < s.size() && isdigit(s[idx])) {
                    idx++;
                }
                // if not reached end 
                if(idx != s.size()) {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                // not a integer exponent
                return false;
            }
        } 
        else {
            return false;
        }
    }
    
    bool checkDecimalInt(string &s, int &idx, bool seenDigit) {
        if(seenDigit && idx == s.size())
            return true;
        // must have digit - wrong
        // can directly go to exponent 
        if (idx < s.size() && seenDigit && (s[idx] == 'e' || s[idx] == 'E')) {
            return checkExponent(s, idx);
        }
        else if(idx < s.size() && isdigit(s[idx])) {
            bool seenDigitHere = false;
            while(idx < s.size() && isdigit(s[idx])) {
                seenDigitHere = true;
                idx++;
            }
            if(idx == s.size()){
                return true;
            }
            else {
                if(seenDigit || seenDigitHere)
                    return checkExponent(s, idx);
                return false;
            }
        }
        else {
            // no digit after '.'
            return false;
        }
        return false;
    }
    
    bool isNumber(string s) {
        // [+/-] 1212 [.] [1212] [ e/E [+/-] [1234] ]
        // 
        int idx = 0;
        
        // check sign
        if (s[idx] == '+' || s[idx] == '-') {
            idx++;
        }
        // check for digit or . 
        if(idx < s.size() && (isdigit(s[idx]) || s[idx] == '.')) {
            if(s[idx] == '.') { // decimal
                idx++;
                // check for inte
                return checkDecimalInt(s, idx, false);
            }
            else if(idx < s.size() && isdigit(s[idx])) {
                bool seenDigit = false;
                while(idx < s.size() && isdigit(s[idx])) {
                    idx++;
                    seenDigit = true;
                }
                if(idx == s.size()){
                    return true;
                }
                else if (idx < s.size()) {
                    // may have decimal
                    // check
                    if (idx < s.size() && s[idx] == '.') {
                        idx++;
                        return checkDecimalInt(s,idx,seenDigit);
                    }
                    else {
                        return checkExponent(s, idx);
                    }
                }
            }
        }
        else {
            return false;
        }
        return false;
    }
};
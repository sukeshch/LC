class Solution {
public:
    inline int is_num(string const &abbr, int& idx) {
        if(!std::isdigit(abbr[idx])) return -1;
        int val = 0;
        while(
            idx < abbr.size() && 
            std::isdigit(abbr[idx])
        ) {
            val = 10*val + (abbr[idx]-'0');
            idx++;
        }
        return val;
    }
    
    bool validWordAbbreviation(string word, string abbr) {
        int w_idx = 0;
        
        int a_idx = 0;
        while(a_idx < abbr.size() && w_idx < word.size()) {
            if(abbr[a_idx] == '0') 
               return false;
            int val = is_num(abbr, a_idx);
            if(val == -1) {
                if(abbr[a_idx] != word[w_idx]) {
                    return false;
                } else {
                    a_idx++;
                    w_idx++;
                }
            } else {
                w_idx += val;
            }
        }
        if(a_idx != abbr.size()) return false;
        if(w_idx != word.size()) return false;
        
        return true;
    }
};
class Solution {
public:
    bool isSubString(int curr[], int target[]) {
        for(int i=0; i<60; i++) {
            if(target[i] != 0 && target[i] > curr[i])
                return false;
        }
        return true;
    } 
    
    string minWindow(string s, string t) {
        int t_count[60]{0};
        {   
            int s_count[60]{0};
            for(auto c : t) {
                s_count[c-'A']++;
            }
            for(auto c : t) {
                t_count[c-'A']++;
                if(t_count[c-'A'] > s_count[c-'A']) {
                    return ""; // edge case if s do not contain all chars in t
                }
            }
        }
        
        int start = 0, end = 0;
        int m = s.size();
        int min_len = s.size();
        int res[2]{0};
        
        int curr_count[60]{0};
        // cout << "s size " << m << endl;
        while(start < m || end < m) {
            // if(start > m-500){
            //     cout << "st : " << start << " end: " << end << endl;
            // }
            if(isSubString(curr_count, t_count)) {
                // cout << "issubstr " << min_len << endl;
                if(min_len >= (end-start)) {
                    min_len = end-start;
                    res[0] = start;
                    res[1] = end;
                }
                curr_count[s[start]-'A']--;
                start++;
            }
            else {
                // cout << "! issubstr" << endl;
                if(end == m) break;
                curr_count[s[end]-'A']++;
                end++;
            }
        }
        
        return s.substr(res[0], res[1]-res[0]);
    }
};
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> left(s.size() + 2, 0);
        vector<int> right(s.size() + 2, 0);
        if(s[0] == '1') left[1] = 1;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i] == '1') left[i+1] = left[i] + 1;
            else left[i+1] = left[i];
        }
        if(s.back() == '0') right[s.size()] = 1;
        for(int i=s.size()-2; i>-1; i--)
        {
            if(s[i] == '0') right[i+1] = right[i+2] + 1;
            else right[i+1] = right[i+2];
        }
        int result = s.size();
        for(int i=0; i<=s.size(); i++) {
            result = min(result, left[i] + right[i+1]);
        }
        return result;   
    }
};
class Solution {
public:
    bool match(int first[], int second[], int len)
    {
        for(int i=0; i<len; i++)
        {
            if(first[i] == 0) continue;
            if(first[i] > second[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        int rl = 0, rr = 0, minl = s.size()+100;
        int l = 0, r = 0;
        int tcount[60]{0};
        for(auto c : t)
            tcount[c-'A']++;
        int scount[60]{0};
        while(r < s.size())
        {
            while(r < s.size() && !match(tcount, scount, 60))
            {
                scount[s[r]-'A']++;
                r++;
            }
            while(match(tcount, scount, 60))
            {
                if(minl > (r-l))
                    rl = l, rr = r, minl = (r-l);
                scount[s[l]-'A']--;
                l++;
            }
        }
        if(minl == 0 || minl > s.size()) return "";
        string result = s.substr(rl, minl);
        return result;
    }
};
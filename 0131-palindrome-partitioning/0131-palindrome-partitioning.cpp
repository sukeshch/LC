class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left = 0, right = s.size()-1;
        while(left <= right) 
        {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        // cout << "here " << s << endl;
        if(s.size() == 0)
            return {{}};
        if(s.size() == 1)
            return {{s}};
        
        vector<vector<string>> res;
        
        for(int i=1; i<=s.size(); i++)
        {
            if(isPalindrome(s.substr(0, i))) 
            {
                auto r = partition(s.substr(i));
                // cout << "r.size() " << r.size() << " " << s.substr(0, i) << "-" << s.substr(i) <<endl; 
                if(r.size() > 0)
                {
                    string p = s.substr(0, i);
                    for(auto rr : r) {
                        rr.insert(rr.begin(), p);
                        res.push_back(rr);
                    }
                }
            }
        }
        return res;
    }
};
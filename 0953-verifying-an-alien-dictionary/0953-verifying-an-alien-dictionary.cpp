class Solution {
public:    
    bool isAlienSorted(vector<string>& words, string order) {
        int lex[26] = {0};
        int counter = 0;
        for(auto c : order)
            lex[(int)(c-'a')] = counter++;
        
        for(int i = 1; i<words.size(); i++)
        {
            int left = 0, right = 0;
            while(left < words[i-1].size() && right < words[i].size() &&
                 (lex[int(words[i-1][left]-'a')] == lex[int(words[i][right]-'a')]) ){
                
                left++; right++;
            }
            
            if(left == words[i-1].size() || right == words[i].size()) {
                if(words[i-1].size() > words[i].size()) 
                    return false;
            }
            else if(lex[int(words[i-1][left]-'a')] > lex[int(words[i][right]-'a')])
                return false;
        }
        return true;
    }
};
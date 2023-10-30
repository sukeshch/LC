class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";
        unordered_map<int, int> counts;
        for(auto t : target)
            counts[t-'a'] = 0;
        
        for(auto t : text) {
            if(counts.find(t-'a') != counts.end())
                counts[t-'a']++;
        }
        int res = text.size();
        for(auto [k, v] : counts)
            if(k != ('o'-'a') && k != ('l'-'a'))
                res = min(res, v);
            else 
                res = min(res, v/2);
        return res;
    }
};
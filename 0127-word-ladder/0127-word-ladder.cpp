class Solution {
public:
    unordered_set<string> getNeig(
        string input, 
        map<string, unordered_set<string>> &t_wmap, 
        unordered_set<string> &visited
    ) {
        unordered_set<string> res; 
        for (int i=0; i < input.size(); i++) {
            string word = input;
            word[i] = '*';
            if (t_wmap.count(word) > 0) {
                for (auto str : t_wmap.at(word)) {
                    if (visited.count(str) == 0) {
                        visited.insert(str);
                        res.insert(str);
                    }
                }
            }
        }
        
        return res;
    }
    
    int bfs(const string& beginWord, const string& endWord, 
             map<string, int> &wmap, 
             map<string, unordered_set<string>> &t_wmap) {
        if (wmap.count(endWord) == 0)
            return 0;
        
        unordered_set<string> visited;
        queue<string> bfs_q;
        
        visited.insert(beginWord);
        bfs_q.push(beginWord);
        
        int depth = 1;
        while(!bfs_q.empty()) {
            depth++;
            
            for (int i=0, sz = bfs_q.size(); i < sz; i++) {
                auto fr = bfs_q.front();
                bfs_q.pop();
                
                auto neigh = getNeig(fr, t_wmap, visited);
                if (neigh.count(endWord)) {
                    return depth;
                }
                
                for(auto elem : neigh) {
                    bfs_q.push(elem);
                }
            }
        }

        return 0;
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // pre processing
        // word --> index
        map<string, int> wmap;
        // regex --> word
        map<string, unordered_set<string>> t_wmap;
        for(int i=0; i<wordList.size(); i++) {
            wmap[wordList[i]] = i;
            
            // transform word
            for (int j=0; j < wordList[i].size(); j++) {
                string word = wordList[i];
                word[j] = '*';
                t_wmap[word].insert(wordList[i]);
            }
        }
        
        return bfs(beginWord, endWord, wmap, t_wmap);
    }
};
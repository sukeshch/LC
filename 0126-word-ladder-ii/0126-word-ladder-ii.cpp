class Solution {
public:
    unordered_set<string> getNeig(
        string input, 
        map<string, unordered_set<string>> &t_wmap, 
        unordered_set<string> &visited,
        map<string, unordered_set<string>> &parent
    ) {
        unordered_set<string> res; 
        for (int i=0; i < input.size(); i++) {
            string word = input;
            word[i] = '*';
            if (t_wmap.count(word) > 0) {
                for (auto str : t_wmap.at(word)) {
                    
                    if (visited.count(str) == 0) {
                        // visited.insert(str);
                        parent[str].insert(input);
                        res.insert(str);
                    }
                }
            }
        }
        if(res.count(input))
            res.erase(input);
        
        return res;
    }
    
    void getValidPaths(
        const string &beginWord,
        vector<string> &path,
        set<vector<string>> &result, 
        map<string, unordered_set<string>> &parent
    ) {
        if (path.back() == beginWord) {
            result.insert(
                vector<string>(path.rbegin(), path.rend())
            );
            return;
        }
        if (parent.count(path.back())) {   
            for (auto elem : parent[path.back()]) {
                path.push_back(elem);
                getValidPaths(beginWord, path, result, parent);
                path.pop_back();
            }
        }
    }
    
    set<vector<string>> bfs(const string& beginWord, const string& endWord, 
             map<string, int> &wmap, 
             map<string, unordered_set<string>> &t_wmap) {
        if (wmap.count(endWord) == 0) {
            // std::unordered_set<vector<string>> empty_set;
            return {};
        }
        
        unordered_set<string> visited;
        queue<string> bfs_q;
        map<string, unordered_set<string>> parent;
        
        visited.insert(beginWord);
        bfs_q.push(beginWord);
        
        set<vector<string>> result;
        
        while(!bfs_q.empty()) {
            
            bool found = false;
            
            unordered_set<string> Ns;
            unordered_set<string> resultnodes;
            
            for (int i=0, sz = bfs_q.size(); i < sz; i++) {
                auto fr = bfs_q.front();
                bfs_q.pop();
                
                auto neigh = getNeig(fr, t_wmap, visited, parent);
                
                if (neigh.count(endWord)) {
                    found = true;
                    resultnodes.insert(fr);
                }
                
                for(auto elem : neigh) {
                    Ns.insert(elem);
                }
            }

            for(auto elem : Ns) {
                visited.insert(elem);
                bfs_q.push(elem);
            }
            
            if (found) {
                vector<string> path;
                path.push_back(endWord);
                for(auto item : resultnodes) {
                    path.push_back(item);
                    getValidPaths(beginWord, path, result, parent);
                    path.pop_back();
                }
                return result;
            }
        }

        return {};
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
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
        
        auto res = bfs(beginWord, endWord, wmap, t_wmap);
        return vector<vector<string>>(res.begin(), res.end());
    }
};
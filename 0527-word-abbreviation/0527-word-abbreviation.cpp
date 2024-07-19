class Solution {
public:
// #define DEBUG  
#ifdef DEBUG
    #define LOG(str) std::cout << str;
    #define LOGN(str) std::cout << str << std::endl;
#else
    #define LOG(str) 
    #define LOGN(str)
#endif
    
    inline std::string getMinAbbr(string inp) {
        if(inp.size() <=3) return inp;
        
        return inp[0] + to_string(inp.size()-2) + inp.back();
    }
    
    struct Trie{
        bool is_end = false;
        unsigned char count = 0;
        unordered_map<char, Trie*> childs;
        ~Trie() {
            for(auto child : childs)
                delete child.second;
        }
    };
    
    void buildTrie(Trie *root, vector<string>& words, vector<int> &ids) {
        LOGN(__func__);
        for(auto id : ids) {
            string word = words[id];
            LOG(word << " ");
            // insert word
            int wIdx = 0;
            Trie *curr = root;
            while(wIdx < word.size()) {
                curr->childs.insert({word[wIdx], new Trie()});
                curr = curr->childs[word[wIdx]];
                curr->count++;
                wIdx++;
            }
            curr->is_end = true;
        }
        LOGN("\nend " << __func__);
    }
    
    typedef string ABBR;
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<ABBR, vector<int>> abbr_mp_;
        vector<string> result(words.size(), "");
        
        { // getMinIndex and push to map
            int index = 0;
            for(auto w : words) {
                auto min_abbr = getMinAbbr(w);
                abbr_mp_[min_abbr].push_back(index);
                LOG(min_abbr << " ")
                index++;
            }
            LOGN("")
        }
        
        for(auto item : abbr_mp_) {
            if(item.second.size() == 1) { // append result if unique abbr
                result[item.second[0]] = item.first;
                continue;
            }
            // handle collision
            // add each word to trie
            Trie *root = new Trie();
            buildTrie(root, words, item.second);
            
            // traverse trie to find unique
            for(auto wIdx : item.second) {
                string word = words[wIdx];
                Trie *curr = root->childs[word[0]];
                int index = 0;
                while(curr->count != 1) {
                    index++;
                    curr = curr->childs[word[index]];
                }
                if(index + 1 < (words[wIdx].size() - 1 - 1) ) {
                    int sz = words[wIdx].size() - 1 - index - 1;
                    result[wIdx] = words[wIdx].substr(0, index+1) + to_string(sz) + words[wIdx].back();
                }
                else {
                    result[wIdx] = words[wIdx];
                }
            }
            delete root;
        }
        
        return result;
    }
};
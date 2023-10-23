class WordDictionary {
    unordered_set<string> words_;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words_.insert(word);
    }
    
    bool search(string word) {
        int dotcount = 0;
        int dotindex[2] = {0};
        for(int i=0; i<word.size(); i++) {
            if(word[i] == '.'){
                dotindex[dotcount] = i;
                dotcount++;
            }
        }
        for(int i=0; i<26 && dotcount == 1; i++) {
            word[dotindex[0]] = 'a' + i;
            if(words_.find(word) != words_.end())
                return true;
        }
        for(int i=0; i<26 && dotcount == 2; i++) {
            for(int j=0; j<26; j++) {
                word[dotindex[0]] = i + 'a';
                word[dotindex[1]] = j + 'a';
                if(words_.find(word) != words_.end())
                    return true;
            }
        }
        return words_.find(word) != words_.end();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
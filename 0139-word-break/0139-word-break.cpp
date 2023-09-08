class Solution {
public:
    struct TrieNode{
        TrieNode* childs[26];
        ~TrieNode() {
            
        }
        bool isWord = false;
        void insert(string word, int index) {
            if(index == word.size()) {
                isWord = true;
                return;
            }
            int c_id = word[index] - 'a';
            if(childs[c_id] == NULL) {
                childs[c_id] = new TrieNode();
            }
            childs[c_id]->insert(word, index+1);
        }
    };
    TrieNode *root;
    
    bool search(string word) {
        TrieNode* curr = root;
        int index = 0;
        while ( curr ) {
            if(index == word.size()) 
                return curr->isWord;
            int c_id = word[index] - 'a';
            if(curr->childs[c_id] == NULL) { // match character
                return false;
            }
            
            curr = curr->childs[c_id];
            index++;
        }
        return false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for(auto word : wordDict) {
            root->insert(word, 0);
        }
        
        vector<bool> dp(s.size() + 1, false);
        dp.back() = true;
        
        for(int i=s.size()-1; i>=0; i--) {
            TrieNode *curr = root;
            bool wordbreak = false;
            int index = i;
            while(curr && index < s.size()) {
                int c_id = s[index] - 'a';
                if(curr->childs[c_id] == NULL) {
                    break;
                }
                curr = curr->childs[c_id];
                if(curr->isWord) {
                    // cout << "index " << index << endl;
                    wordbreak |= dp[index+1];
                    if(wordbreak) break;
                }
                index++;
            }
            dp[i] = wordbreak;
            // cout << i << " : " << dp[i] << endl;
        }
        
        return dp[0];
    }
};
class Trie {
    struct Node{
        bool is_word;
        Node *childs[26] = {};
        // ~Node() {
        //     for(int i=0; i<26; i++) {
        //         if(childs[i] != NULL)
        //             delete childs[i];
        //     }
        // }
    };
    Node *root;
public:
    
    Trie() {
        root = new Node();
        root->is_word = false;
    }
    
    void insert(string word) {
        auto curr = root;
        
        for(auto c : word) {
            // cout << "Insert " << word << " : " << c << endl;
            int val = c-'a';
            if(curr->childs[val] == NULL) {
                curr->childs[val] = new Node();
            }
            curr = curr->childs[val];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        auto curr = root;
        int cidx = 0;
        while(curr) {
            int val = word[cidx] - 'a';
            if(curr->childs[val] != NULL) {
                curr = curr->childs[val];
                cidx++;
            } else {
                return false;
            }
            if ( cidx == word.size()) {
                if(curr->is_word) return true;
                return false;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        int cidx = 0;
        while(curr) {
            int val = prefix[cidx] - 'a';
            if(curr->childs[val] != NULL) {
                curr = curr->childs[val];
                cidx++;
            } else {
                return false;
            }
            if (cidx == prefix.size()) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
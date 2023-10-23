class WordDictionary {
    struct Node{
        bool is_word = false;
        Node *childs[26];
    };
    Node *root;
    bool search(string word, int index, Node* root) {
        if(!root) return false;
        if(index == word.size())
            return root->is_word;
        if(word[index] != '.')
            return search(word, index + 1, root->childs[word[index]-'a']);
        for(int i=0; i<26; i++) {
            if(root->childs[i] != NULL){
                if(search(word, index+1, root->childs[i]))
                    return true;
            }
        }
        return false;
    }
    
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *curr = root;
        for(auto c : word) {
            if(curr->childs[c-'a'] == NULL)
                curr->childs[c-'a'] = new Node();
            curr = curr->childs[c-'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class Solution {
public:
    class Node {
    private:
        vector<Node*> childs_;
        vector<string> data_;
        string current_;
    public:
        Node(string c = " ") : current_(c) {
            childs_.resize(26, NULL);
        }
        void insert(Node* t, string str) {
            int index = str[0]-'a';

            Node *croot = t;
            for(int i=0; i<str.size(); i++) {
                index = str[i] - 'a';
                if(!croot->childs_[index]) {
                    croot->childs_[index] = new Node(str.substr(0, i+1));
                }
                croot = croot->childs_[index];

                if(croot->data_.size() < 3) {
                    croot->data_.push_back(str);
                }
            }

        }
        vector<vector<string>> search(Node* t, string word) {
            vector<vector<string>> result;

            int index = word[0]-'a';
            Node *croot = t;

            for(int i=0; i<word.size(); i++) {
                index = word[i] - 'a';
                if(!croot->childs_[index]) {
                    while(i < word.size()) {
                        result.push_back({});
                        i++;
                    }
                    break;
                }
                croot = croot->childs_[index];
                result.push_back(croot->data_);
            }

            return result;
        }
    } root;
    
    
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<string> cpy_prod(products);
        std::sort(cpy_prod.begin(), cpy_prod.end());
        
        // Build Trie
        for(auto prod : cpy_prod) {
            root.insert(&root, prod);
        }
        
        return root.search(&root, searchWord);
    }
};
class TrieNode {
    public:
        bool exist;
        // char c;  其实不需要这一项
        TrieNode* branch[26];
    
    TrieNode() {
        exist = false;
        memset(branch, 0, sizeof(branch));
    }
};


class Trie {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tr = root;
        for (auto ch : word){
            if (!(tr->branch[ch-'a'])) {
                tr->branch[ch-'a'] = new TrieNode();
            }
            tr = tr->branch[ch-'a'];
        }
        tr->exist = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tr = root;
        for (auto ch : word){
            if (!(tr->branch[ch-'a']))
                return false;
            tr = tr->branch[ch-'a'];
        }
        return tr->exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tr = root;
        for (auto ch : prefix){
            if (!(tr->branch[ch-'a']))
                return false;
            tr = tr->branch[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

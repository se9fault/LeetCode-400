/*
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing
only letters a-z or .. A . means it can represent any one letter.

Example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note: You may assume that all words are consist of lowercase letters a-z.
*/

struct TrieNode {
    TrieNode *next[26];
    bool is_word;
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() : root(new TrieNode()) {}
    ~WordDictionary() { clean(root); }
  
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            TrieNode *&next = p->next[word[i] - 'a'];
            if (next == nullptr)
                next = new TrieNode();
            p = next;
        }
        p->is_word = true;
    }
  
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
private:
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> next[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> next[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> is_word;
    }

    void clean(TrieNode *root) {
        for (int i = 0; i < 26; ++i) {
            if (root->next[i] != nullptr) {
                clean(root->next[i]);
            }
        }
        delete root;
    }
};

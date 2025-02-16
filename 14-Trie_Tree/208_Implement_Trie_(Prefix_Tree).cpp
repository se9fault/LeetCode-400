/*
Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true

Note:
  You may assume that all inputs are consist of lowercase letters a-z.
  All inputs are guaranteed to be non-empty strings.
*/

#define ARRAY_WITH_NODE
#ifdef ARRAY_WITH_NODE
struct TrieNode {
    TrieNode *next[26];
    bool is_word;
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() : root(new TrieNode()) {}
    ~Trie() { clean(root); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            TrieNode *&next = p->next[word[i] - 'a'];
            if (next == nullptr)
                next = new TrieNode();
            p = next;
        }
        p->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p != nullptr && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    TrieNode *find(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size() && p != nullptr; ++i)
            p = p -> next[word[i] - 'a'];
        return p;
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
#endif

// Need to be very careful with map<>, because even a [] read access will insert
// 0 value into the map.
// Method above is more recommended.
//#define MAP_WITHOUT_NODE
#ifdef MAP_WITHOUT_NODE
class Trie {
private:
    map<char, Trie*> next = {};
    bool isword = false;
public:
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->next.count(c))
                node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isword = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->next.count(c))
                return false;
            node = node->next[c];
        }
        return node->isword;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (!node->next.count(c))
                return false;
            node = node->next[c];
        }
        return true;
    }
};
#endif
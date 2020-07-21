class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty())
            return res;
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        Trie T; // put all target words in Trie to prune
        for (auto &a : words)
            T.insert(a);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                TrieNode *next = T.root->child[board[i][j] - 'a'];
                if (next) {
                    dfs(board, next, i, j, visited, res);
                }
            }
        }
        return res;
    }

private:
    int m, n;
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i])
                    p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    // TODO: Need to change this "str" in TrieNode to use the is_word bool in TrieNode
    void dfs(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visited, vector<string>& res) {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            TrieNode* next = p->child[board[nx][ny] - 'a'];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && next != nullptr) {
                dfs(board, next, nx, ny, visited, res);
            }
        }
        visited[i][j] = false;
    }
};
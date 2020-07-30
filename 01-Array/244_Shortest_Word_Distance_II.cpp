/*
This is a follow up of Shortest Word Distance. The only difference is now you
are given the list of words and your method will be called repeatedly many times
with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements
a method that takes two words word1 and word2 and return the shortest distance
between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Given word1 = "coding", word2 = "practice", return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both
in the list.
*/


// Solution:
// create hash table to store the words and the index where they appeared.
// Time complexity is O(M+N), in which M, N is the time two words appeared.
class WordDistance {
public:
    // initialize, add all words into the map
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    // go through the two vectors of word1 and word2, find minimum distance
    int shortest(string word1, string word2) {
        int i = 0, j = 0, res = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? ++i : ++j;
            // every time only moves the smaller one, so diff could be smaller
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> m; // stores (word, [all appeared index])
};

/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.

Solution: solution in LC243 Word Distance 1 still works, with one modification on line 26.
*/

class Solution {
public:
    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        int idx = -1, ans = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && (words[i] != words[idx] || word1 == word2)) { // changed
                    ans = min(ans, i - idx);
                }
                idx = i;
            }
        }
        return ans;
    }
};

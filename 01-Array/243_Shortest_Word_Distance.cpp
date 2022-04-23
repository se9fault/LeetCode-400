/*
Given a list of words and two words word1 and word2, return the shortest
distance between these two words in the list.
You may assume that word1 does not equal to word2, and word1 and word2 are both
in the list.

Example 1:
Input: ["practice", "makes", "perfect", "coding", "makes"],"coding","practice"
Output: 3
Explanation：index("coding") - index("practice") = 3

Example 2:
Input: ["practice", "makes", "perfect", "coding", "makes"],"makes","coding"
Output: 1
Explanation：index("makes") - index("coding") = 1
*/


// Solution:
//   Use an variable `idx` to store the idx of either words' last apperance in
//   the vector, and calculate and compare diff when another word appears.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        int idx = -1, ans = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && words[i] != words[idx]) {
                    ans = min(ans, i - idx);
                }
                idx = i;
            }
        }
        return ans;
    }
};

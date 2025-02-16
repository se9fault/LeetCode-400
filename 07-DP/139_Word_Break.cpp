/*
Given a non-empty string s and a dictionary wordDict containing a list of
non-empty words, determine if s can be segmented into a space-separated
sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the
segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as
"apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        int maxWordLength = 0; // prune optimization
        for (auto word : wordDict) {
            words.insert(word);
            maxWordLength = max((int)word.size(), maxWordLength);
        }

        int n = s.size();
        vector<bool> dp(n + 1, false); // is substr[0, idx] segmentable
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= max(i - maxWordLength, 0); --j) { // start with substr w/ length 1
                if (dp[j]) {
                    string following = s.substr(j, i - j);
                    if (words.find(following) != words.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

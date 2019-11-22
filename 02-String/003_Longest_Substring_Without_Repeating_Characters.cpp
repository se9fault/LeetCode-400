/*
Given a string, find the length of the longest substring without repeating
characters.

Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a
             subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int i = 0, j = 0, ans = 0;
        for (i = 0; j < s.length(); ++j) {
            if (hash.find(s[j]) != hash.end()) {
                i = max(i, hash[s[j]]);
            }
            ans = max(ans, j - i + 1);
            hash[s[j]] = j + 1;
        }
        return ans;
    }
};

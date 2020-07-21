/*
Given a string s, find the length of the longest substring t that contains at
most 2 distinct characters.

Example 1:
Input: "eceba"      Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:
Input: "ccaabbb"    Output: 5
Explanation: t is "aabbb" which its length is 5.


Solution:
1. HashMap, (char, number of times it appeared) (applicable to k distinct char)
    Also store the left position, and always maintains map size to be 2.
    If a third pair occurs, move the `left` mark, until one pair has 0 count in
    the map.
2. HashMap, (char, last appeared location) (applicable to k distinct char)
3. sliding window (only for 2 distinct char)
    left:  start location of the substring
    right: end location of the window, pointing to the last position of another
           char (the char different from s[i]). Therefore if another char
           enters, left should jump to right+1.
           e.g. eceeeeeeb, when i is at 'b', left would be at 0, right would be
                at 'c'.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = -1, ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1])
                continue; // do not update right
            if (right >= 0 && s[right] != s[i]) {
                // a third char entered, move left to exit a char
                ans = max(ans, i - left);
                left = right + 1;
            }
            right = i - 1;
        }
        return max(s.size() - left, res);
    }
};

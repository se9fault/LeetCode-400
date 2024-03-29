/*
Given two strings s and t, determine if they are both one edit distance apart.

Note:
There are 3 possiblities to satisify one edit distance apart:
* Insert a character into s to get t
* Delete a character from s to get t
* Replace a character of s to get t

Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:
Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.

Example 3:
Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < min(s.size(), t.size()); ++i) {
            if (s[i] != t[i]) {
                if (s.size() == t.size())
                    return s.substr(i + 1) == t.substr(i + 1); // replace
                if (s.size() < t.size())
                    return s.substr(i) == t.substr(i + 1);
                else
                    return s.substr(i + 1) == t.substr(i);
            }
        }
        return abs((int)s.size() - (int)t.size()) == 1;
    }
};

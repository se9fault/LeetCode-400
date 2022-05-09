/*
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
Example 1:
Input: "A"
Output: 1

Example 2:
Input: "AB"
Output: 28

Example 3:
Input: "ZY"
Output: 701
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int titleToNumber(string s) {
        int cnum = 0;
        for (int i = 0; i < s.length(); i++) {
            cnum *= 26;
            cnum += s[i] - 'A' + 1;
        }
        return cnum;
    }
};

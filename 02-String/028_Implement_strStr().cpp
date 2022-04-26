/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question
to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int strStr(string str1, string str2) { // KMP
        if (str1.size() < str2.size())
            return -1;
        if (str1.size() == 0 || str2.size() == 0)
            return 0;
        int i1 = 0;
        int i2 = 0;
        vector<int> next = getNextArray(str2);
        while (i1 < str1.size() && i2 < str2.size()) {
            if (str1[i1] == str2[i2]) {
                i1++;
                i2++;
            } else if (next[i2] == -1) {
                // 失配，且 i2 已经回退到了 0 位置，只能让 i1 往后跳
                i1++;
            } else {
                i2 = next[i2];
                // 失配，让 i2 往前跳到前缀的后面位置
            }
        }
        return i2 == str2.size() ? i1 - i2 : -1;
    }

private:
    vector<int> getNextArray(string str2) {
        if (str2.size() == 1)
            return vector<int>{-1};

        vector<int> next(str2.size());
        next[0] = -1;
        next[1] = 0;
        int i = 2, cn = 0;
        while (i < next.size()) { // 相当于递推，由 next[0, i-1] 求出 next[i]
            if (str2[i - 1] == str2[cn]) {	// 若 i-1 位置(后缀) 等于 cn 位置(前缀)
                next[i++]= ++cn;			// 那么 next[i] 就是 next[i-1] + 1
            } else if (cn > 0) {			// 两位置不等，再找有没有小一截的
                cn = next[cn];				// 利用 next 快速跳转
            } else {
                next[i++] = 0;
            }
        }
        return next;
    }
};

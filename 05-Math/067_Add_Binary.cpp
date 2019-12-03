/*
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int i = a.size(), j = b.size(), c = 0;
        while (i || j || c) {
            c += (i && (a[--i] - '0')) + (j && (b[--j] - '0'));
            sum.insert(0, 1, c % 2 + '0');
            c /= 2;
        }
        return sum;
    }
};

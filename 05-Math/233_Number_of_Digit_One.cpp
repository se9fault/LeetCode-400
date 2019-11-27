/*
Given an integer n, count the total number of digit 1 appearing in all
non-negative integers less than or equal to n.

Example:    Input: 13    Output: 6
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Solution: see https://leetcode.com/problems/number-of-digit-one/discuss/64381/4%2B-lines-O(log-n)-C%2B%2BJavaPython
*/

class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10)
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
        return ones;
    }
};

/*
Given two non-negative integers num1 and num2 represented as strings, return the
product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to
integer directly.

Solution: pre-allocate answer string, work from back to front. even in multiply,
(single digit * single digit + original) only affect two digits.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        string ans(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = len2 - 1; j >= 0; --j) {
                int sum = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                ans[i + j + 1] = sum % 10 + '0';
                carry = sum / 10;
            }
            ans[i] += carry; // if remains a carry, write it down directly, at i
        }

        int startPos = ans.find_first_not_of('0');
        if (startPos != -1) {
            return ans.substr(startPos);
        }
        return "0";
    }
};

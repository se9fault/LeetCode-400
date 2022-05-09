/*
Convert a non-negative integer to its english words representation. Given input
is guaranteed to be less than 2^31 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven \
Thousand Eight Hundred Ninety One"
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    string numberToWords(int n) {
        return n ? toWords(n).substr(1) : "Zero";
    }
private:
    vector<string> ones = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"
    };

    string toWords(int n) {
        if (n >= 1000000000) {
            return toWords(n / 1000000000) + " Billion" + toWords(n % 1000000000);
        }
        if (n >= 1000000) {
            return toWords(n / 1000000) + " Million" + toWords(n % 1000000);
        }
        if (n >= 1000) {
            return toWords(n / 1000) + " Thousand" + toWords(n % 1000);
        }
        if (n >= 100) {
            return toWords(n / 100) + " Hundred" + toWords(n % 100);
        }
        if (n >= 20) {
            return " " + tens[n / 10] + toWords(n % 10);
        }
        if (n >= 1) {
            return " " + ones[n];
        }
        return "";
    }
};

/*
Calculate the sum of two integers a and b, but you are not allowed to use the
operator + and -.

Example 1: Input: a = 1, b = 2  Output: 3
Example 2: Input: a = -2, b = 3 Output: 1
*/

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // All 1s in carry will represent positions
            // where addition will result in to carry
            int carry = a & b;
            // sum of a and b without considering carry
            a = a ^ b;
            // typecasting to handle negative number
            // << 1 will shift the carry bits to the position
            // where these bits are to be added.
            b = (unsigned int)carry << 1;
        }
        return a;
    }
};

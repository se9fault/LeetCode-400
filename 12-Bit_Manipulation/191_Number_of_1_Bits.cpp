/*
Write a function that takes an unsigned integer and return the number of '1'
bits it has (also known as the Hamming weight).

Example 1: Input: 00000000000000000000000000001011    Output: 3
Example 2: Input: 00000000000000000000000010000000    Output: 1
Example 3: Input: 11111111111111111111111111111101    Output: 31

Note:
Note that in some languages such as Java, there is no unsigned integer type. In
this case, the input will be given as signed integer type and should not affect
your implementation, as the internal binary representation of the integer is the
same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement
notation. Therefore, in Example 3 above the input represents the signed integer
-3.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        // time complexity O(result). clear least significant bit at a time
        while (n != 0) {
            result++;
            n = n & (n - 1);
        }
        return result;
    }
};

# 12-Bit_Manipulation
Note: Click on the number to go to the source code; click on the name to go to the LeetCode website.

- [ ] [318](318_Maximum_Product_of_Word_Lengths.cpp) [Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/description/) Infrequent

- [x] [393](393_UTF-8_Validation.cpp) [UTF-8 Validation](https://leetcode.com/problems/utf-8-validation/description/)

- [ ] [201](201_Bitwise_AND_of_Numbers_Range.cpp) [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)

- [x] [371](371_Sum_of_Two_Integers.cpp) [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/description/)

    Given 2 ints, return sum without using +/-.
    Ex. `a = 1 b = 2 -> 3, a = 2 b = 3 -> 5`

    Use AND`&` to get carry bit, and XOR`^` to add. No need to calculate bits one by one; store all carry bits, shift them and add, until carry bits are empty.

- [ ] [089](089_Gray_Code.cpp) [Gray Code](https://leetcode.com/problems/gray-code/description/)

- [x] [137](137_Single_Number_II.cpp) [Single Number II](https://leetcode.com/problems/single-number-ii/description/)


## Single '1' Bits

- [x] [191](191_Number_of_1_Bits.cpp) [Number of 1 Bits](https://leetcode.com/problems/number-of-01-bits/description/)

    Return number of '1' bits in an int.
    Ex. `n = 00001011 -> 3`

    `n & (n - 1)` drops the least significant `1` bit from `n`.

- [x] [190](190_Reverse_Bits.cpp) [Reverse Bits](https://leetcode.com/problems/reverse-bits/description/)

- [x] [338](338_Counting_Bits.cpp) [Counting Bits](https://leetcode.com/problems/counting-bits/description/)


## XOR

- [x] [268](268_Missing_Number.cpp) [Missing Number](https://leetcode.com/problems/missing-number/description/)

    Given array in range `[0, n]`, return missing number.
    Ex. `nums = [3,0,1] -> 2`, `nums = [0,1] -> 2`

    XOR`^` is its own inverse, so a number XORed twice would be canceled out. We XOR all `nums` and `[0,n]`, then the missing number would be XORed only once.

- [x] [389](389_Find_the_Difference.cpp) [Find the Difference](https://leetcode.com/problems/find-the-difference/description/)

- [x] [136](136_Single_Number.cpp) [Single Number](https://leetcode.com/problems/single-number/description/)

- [x] [260](260_Single_Number_III.cpp) [Single Number III](https://leetcode.com/problems/single-number-iii/description/)

/*
Given a string, determine if a permutation of the string could form a
palindrome.

Example 1:    Input: "code"       Output: false
Example 2:    Input: "aab"        Output: true
Example 3:    Input: "carerac"    Output: true

Hint:
Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome.
How about character which occurs odd number of times?
*/

// Solution:
//   A permutation of a palindrome means only 0 or 1 character appeared odd
//   number of times in the string.
//   To save the most space, we use a bitset to store the odd/even times; we
//   count by flip the bit, and use bitset::count() to check how many bits are
//   set in the end.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (auto a : s) {
            b.flip(a);
        }
        return b.count() <= 1;
    }
};

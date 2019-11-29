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

Solution: a permutation of a palindrome means only 0 or 1 character appeared
odd number of times in the string.
*/

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

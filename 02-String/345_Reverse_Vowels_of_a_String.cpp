/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

Example 1:
Input: "hello"
Output: "holle"

Example 2:
Input: "leetcode"
Output: "leotcede"

Note:
The vowels does not include the letter "y".
*/

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1; // two pointers, find vowel, swap
        while (i < j) {
            while (!isVowel(s[i]) && i < s.size()) i++;
            while (!isVowel(s[j]) && j > 0) j--;
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }

    bool isVowel(const char& c) {
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }
};

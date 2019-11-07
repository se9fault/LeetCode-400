/*
Given two strings s and t , write a function to determine if t is an anagram of
s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

Solution: also count for both strings, but can count in the same array.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int counter[26];
        memset(counter, 0, sizeof(counter));
        for (int i = 0; i < s.size(); i++) {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }
        for (int count : counter) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};

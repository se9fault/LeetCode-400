/*
Given an arbitrary ransom note string and another string containing letters from
all the magazines, write a function that will return true if the ransom note can
be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

Solution: count characters on both strings, and do comparision.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> c1, c2;
        for (auto ch : ransomNote) {
            ++c1[ch];
        }
        for (auto ch : magazine) {
            ++c2[ch];
        }
        for (auto pair : c1) {
            if (c2[pair.first] < pair.second) {
                return false;
            }
        }
        return true;
    }
};

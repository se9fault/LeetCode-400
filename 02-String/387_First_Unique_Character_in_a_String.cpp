/*
Given a string, find the first non-repeating character in it and return it's
index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count; // could use a int[26]
        for (auto ch : s) {
            ++count[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

/*
class Solution {
public:
    int firstUniqChar(string s) {
        array<int, 26> firstAppear;
        firstAppear.fill(-1); // -1: never appeared, -2: appeared multiple times
        for (int i = 0; i < s.size(); ++i) {
            auto idx = s[i] - 'a';
            if (firstAppear[idx] == -1) {
                firstAppear[idx] = i;
            } else if (firstAppear[idx] >= 0) {
                firstAppear[idx] = -2;
            }
        }
        int min = INT_MAX;
        bool changed = false;
        for (auto it = firstAppear.begin(); it != firstAppear.end(); it++) {
            if (*it >=0 && *it < min) {
                min = *it;
                changed = true;
            }
        }
        return changed ? min : -1;
    }
};
*/

/*
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

// Solution:
//   Anagrams of the same group will have identical sorted output, therefore use
//   it as key in <sorted key, multiset<strings>>.
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> dict;
        // (sorted string, all anagrams in the multiset)
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            dict[key].insert(str);
        }

        // got the answer in dict now, construct return struct
        vector<vector<string>> anagrams;
        for (auto m : dict) {
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};

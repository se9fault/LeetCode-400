/*
Given a string, we can "shift" each of its letter to its successive letter, for
example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all
strings that belong to the same shifting sequence.

Example:
Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

*/

// Solution:
//   group "abc" "bcd" "xyz" "yza" all share the key "0,1,2".
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (auto str : strings) {
            string temp = "";
            for (auto c : str) {
                temp += to_string((c + 26 - a[0]) % 26) + ","; // abc -> 0,1,2
            }
            m[temp].push_back(str);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it.second.begin(), it.second.end());
        }
        return res;
    }
};

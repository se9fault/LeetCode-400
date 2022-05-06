/*
Given a list of non-negative integers `nums`, arrange them such that they form
the largest number and return it.

Since the result may be very large, so you need to return a string instead of an
integer.

Example 1:
Input: [10,2]
Output: "210"

Example 2:
Input: [3,30,34,5,9]
Output: "9534330"

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 10^9
*/

// Solution:
//   Sort `nums` by using the concatenation of two comparing strings.
//   * sort each string lexicographically works when the leading digits are
//     different (like {9, 10}, 9 > 10, and putting 9 before 10 is correct)
//   * but when the leading digits are the same (e.g. {3, 30}), 3 is
//     lexicograpically smaller, 30 > 3, but putting 30 before 3 (303) is
//     smaller than the other way around (330).
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums)
            strs.push_back(to_string(num));

        // sort two strings by using their concatenation
        auto cmp = [](string &s1, string &s2) {
            return s1 + s2 > s2 + s1;
        };
        sort(strs.begin(), strs.end(), cmp);

        string result = "";
        for (auto str : strs) {
            result += str;
        }

        // get rid of leading zeros (expect when result == "0")
        while (result[0] == '0' && result.size() > 1) {
            result.erase(result.begin());
        }
        return result;
    }
};

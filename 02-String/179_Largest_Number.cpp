/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:
Input: [10,2]
Output: "210"

Example 2:
Input: [3,30,34,5,9]
Output: "9534330"
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums)
            strs.push_back(std::to_string(num));

        // sort by using their concatenation
        // compare single string lexicographically will have problem with {3, 30}
        auto cmp = [](string &s1, string &s2) {
            return s1 + s2 > s2 + s1;
        };
        sort(strs.begin(), strs.end(), cmp);

        string result = "";
        for (auto str : strs) {
            result += str;
        }

        // get rid of leading zeros (expect result = "0")
        while (result[0] == '0' && result.size() > 1) {
            result.erase(result.begin());
        }
        return result;
    }
};

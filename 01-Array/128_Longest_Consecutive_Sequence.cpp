/*
Given an unsorted array of integers, find the length of the longest
consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
*/

// Solutions:
//   1) Use an unordered_set to store all the nums, and try to expand with each
//      num. Once a num is used, erase it from the set
//   2) Use an unordered_map<num, LCS so far>, and whenever a num enters, update
//      LCS on both sides of the num
class Solution {
public:
    int longestConsecutive(vector<int>& nums) { // solution 1
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto num : nums) {
            if (s.find(num) == s.end()) {
                continue;
            }
            int prev = num - 1, next = num + 1;
            while (s.find(prev) != s.end()) {
                s.erase(prev--);
            }
            while (s.find(next) != s.end()) {
                s.erase(next++);
            }
            s.erase(num);
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }

    int longestConsecutive(vector<int> &num) { // solution 2
        unordered_map<int, int> m;
        // (num, longest sequence including this num, that we've seen so far)
        int result = 0;
        for (int i : num) {
            if (m[i])
            // if m[i] exist, then it's possible that it's an old value, skip
                continue;
            int len = m[i + 1] + m[i - 1] + 1;
            // here we only update two borders because that's what will be used
            m[i - m[i - 1]] = len;
            m[i + m[i + 1]] = len;
            m[i] = len;
            result = max(result, len);
        }
        return result;
    }
};

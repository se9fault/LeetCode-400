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
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> m;
        // (num, longest sequence including this num, that we've seen so far)
        int result = 0;
        for (int i : num) {
            if (m[i])
                continue;
            int len = m[i + 1] + m[i - 1] + 1;
            m[i - m[i - 1]] = len;
            m[i + m[i + 1]] = len;
            m[i] = len;
            result = max(result, len);
        }
        return result;
    }
};

/*
Given a set of non-overlapping intervals, insert a new interval into the
intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start
times.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool pushed = false;
        for (auto interval : intervals) {
            if (interval[1] < newInterval[0]) {
                res.push_back(interval);
            } else if (interval[0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            } else {
                if (!pushed) {
                    res.push_back(newInterval);
                    pushed = true;
                }
                res.push_back(interval);
            }
        }
        if (!pushed) {
            res.push_back(newInterval);
        }
        return res;
    }
};

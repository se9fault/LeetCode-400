/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), &cmp);
        vector<Interval> results;

        for (auto interval : intervals) {
            if (results.empty() || results.back().end < interval.start)
                results.push_back(interval);
            else
                results.back().end = std::max(results.back().end, interval.end);
        }
        return results;
    }

    static bool cmp(const Interval &v1, const Interval &v2) {
        return v1.start < v2.start;
    }
};

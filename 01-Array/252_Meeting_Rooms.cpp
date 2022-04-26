/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all
meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
*/

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// Note: method signature may not be accurate.
// Time Complexity: O(NlogN)
// Space Complexity: O(1)
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() <= 1)
            return true;
        auto cmp = [](const Interval& left, const Interval& right) {
            return left.end < right.end;
        };
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i].end > intervals[i + 1].start)
                return false;
        }
        return true;
    }
};

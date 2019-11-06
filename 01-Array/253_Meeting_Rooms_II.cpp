/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
required.

Example1
Input: intervals = [(0,30),(5,10),(15,20),(30,60)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30),(30,60)
room2: (5,10),(15,20)

Example2
Input: intervals = [(2,7)]
Output: 1
Explanation: 
Only need one meeting room
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        if (intervals.size() <= 1)
            return 1;
        map<int, int> m;
        for (auto interval : intervals) {
            ++m[interval.start];
            --m[interval.end];
        }
        // [(0,30),(5,10),(15,20),(30,60)]
        // m: (0,1) (5,1) (10,-1) (15,1) (20,-1) (30,0) (60,-1)
        int rooms = 0; // current rooms we need
        int ans = 0;
        for (auto it : m) {
            ans = max(ans, rooms += it.second);
            // if it.second < 0, then ans will not change
        }
        return ans;
    }
};

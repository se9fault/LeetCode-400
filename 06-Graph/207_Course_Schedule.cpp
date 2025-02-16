/*
There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] =
[a_i, b_i] indicates that you must take course bi first if you want to take
course a_i.

    For example, the pair [0, 1], indicates that to take course 0 you have to
    first take course 1.

Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you
should also have finished course 1. So it is impossible.


Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= a_i, b_i < numCourses
    All the pairs prerequisites[i] are unique.
*/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> out(numCourses, vector<int>()); // out[idx] contains its out edges
        vector<int> in(numCourses); // in[idx] contains the count of its in edges
        for (auto pre : prerequisites) {
            int from = pre[1], to = pre[0]; // [0, 1] -> take 1 then 0 ->  node1 -> node0
            out[from].push_back(to);
            ++in[to];
        }

        queue<int> zq; // queue of nodes with 0 in edges;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) {
                zq.push(i);
            }
        }

        while (!zq.empty()) {
            int t = zq.front();
            zq.pop();
            for (auto o : out[t]) {
                --in[o];
                if (in[o] == 0) {
                    zq.push(o);
                }
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

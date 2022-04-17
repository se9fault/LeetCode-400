/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among
them, there may exist one celebrity. The definition of a celebrity is that all
the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one.
The only thing you are allowed to do is to ask questions like: "Hi, A. Do you
know B?" to get information of whether A knows B. You need to find out the
celebrity (or verify there is not one) by asking as few questions as possible
(in the asymptotic sense).

You are given a helper function bool knows(a, b)which tells you whether A knows
B. Implement a function int findCelebrity(n). There will be exactly on
celebrity if he/she is in the party. Return the celebrity's label if there is a
celebrity in the party. If there is no celebrity, return -1.

Example 1:
Input: graph = [
  [1,1,0],
  [0,1,0],
  [1,1,1]
]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1
means person i knows person j, otherwise graph[i][j] = 0 means person i does not
know person j. The celebrity is the person labeled as 1 because both 0 and 2
know him but 1 does not know anybody.

Note:
The directed graph is represented as an adjacency matrix, which is an n x n
matrix where a[i][j] = 1 means person i knows person j while a[i][j] = 0 means
the contrary.
Remember that you won't have direct access to the adjacency matrix.
*/

bool knows(int a, int b); /// a knows b

// Solution:
//   All the nodes points to the celebrity, so use a celebrity candidate and
//   validate the candidate through 3 passes.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 0; i < n; ++i) {
            // this candidate is the only possible candidate, because
            // 1. if celebrity is 0, then knows(0, i) is always false,
            //    candidate is never changed
            // 2. if celebrity is m (0 < m < n),
            //    then when i == m, knows(cand, m) is true, candidate = m,
            //    and candidate stays m iff for i in [m+1, n), knows(m, i) are
            //    all false (meaning candidate doesn't know anyone behind)
            if (knows(candidate, i))
                candidate = i;
        }
        for (int i = 0; i < candidate; ++i) {
            // verify this candidate; verification will fail if:
            // (1) if candidate knows anyone before candidate
            // (2) if anyone before candidate doesn't know the candiate
            if (knows(candidate, i) || !knows(i, candidate))
                return -1;
        }
        for (int i = candidate + 1; i < n; ++i) {
            // verify this candidate; verification will fail if:
            // (1) if anyone after candidate doesn't know the candiate
            if (!knows(i, candidate))
                return -1;
        }
        return candidate;
    }
};

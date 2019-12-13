/*
Given n points on a 2D plane, find the maximum number of points that lie on the
same straight line.

Example 1:
Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4

Example 2:
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicate;
                    continue;
                }
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            ans = max(ans, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                ans = max(ans, it->second + duplicate);
            }
        }
        return ans;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};

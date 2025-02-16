/*
There is a fence with n posts, each post can be painted with one of the k
colors.
You have to paint all the posts such that no more than two adjacent fence posts
have the same color.
Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

Solution:
  same[i]: total ways to paint, if color(i) == color(i-1)
  diff[i]: total ways to paint, if color(i) != color(i-1)

  same[i] = diff[i-1] * 1
    If we want color(i) == color(i-1), we can only use diff[i-1], because
    same[i - 1] means color(i-1) == color(i-2), and color can only repeat twice.
    Because we want the same color, we have 1 way to paint color(i).

  diff[i] = (same[i-1] + diff[i-1]) * (k-1)
    If we want color(i) != color(i-1), then same[i-1] and diff[i-1] can both be
    used. Excluding the color used in color(i-1), we have (k-1) colors to use.
*/

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        int same = 0, diff = k;
        for (int i = 2; i <= n; ++i) {
            int t = diff;
            diff = (same + diff) * (k - 1);
            same = t;
        }
        return same + diff;
    }
};

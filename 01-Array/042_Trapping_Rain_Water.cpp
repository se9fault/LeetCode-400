/*
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it is able to trap after raining.

Example 1:
        |
    3   |
    2   |                               X
    1   |               X   o   o   o   X   X   o   X
    0   |       X   o   X   X   o   X   X   X   X   X   X
        ----------------------------------------------------
            0   1   2   3   4   5   6   7   8   9

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (marked X) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (marked o) are
being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
    n == height.length
    1 <= n <= 2 * 10^4
    0 <= height[i] <= 10^5
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int ans = 0;
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        right_max[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
            // The maximum height when viewing from the left.
            // Increase monotically when i++
        }
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
            // The maximum height when viewing from the right.
            // Increase monotically when i--
        }

        for (int i = 1; i < n - 1; i++) {
            // logic: for every grid, the water it can hold = the min of left
            // boundary and right boundary - the height of this grid
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

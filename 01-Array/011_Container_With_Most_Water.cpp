/*
Given n non-negative integers a1, a2, ..., an , where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/


// Solution: two pointer, starting from two sides.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]); // lower of the two
            water = max(water, (j - i) * h);
            // Going towards middle means loss of width, so we need to get
            // higher to possibly hold more water. Therefore we move until we
            // get the shorter side a higher edge
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
            // only one of two whiles will be executed
        }
        return water;
    }
};

/*
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it is able to trap after raining.

*/

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
            // 左侧最大值：左视图，能看到的最大高度
        }
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
            // 右侧最大值：右视图，能看到的最大高度
        }

        for (int i = 1; i < n - 1; i++) {
            // 逻辑：每一格上面能装的水 = min(左侧最大值，右侧最大值) - 该格高度
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

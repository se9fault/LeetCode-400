/*
Given a sorted array of integers nums and integer values a, band c. Apply a
quadratic function of the form f(x) = ax^2 + bx + c to each element x in the
array.
The returned array must be in sorted order.
Expected time complexity: O(n)

Example 1:
Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]

Example 2:
Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]

Solution: use the property of parabola, there are always a top point, depending
on a (a > 0 / a < 0 / a = 0).
*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<int> res(n);
        int idx = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            if (a >= 0) {
                res[idx--] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c) ? cal(nums[i++], a, b, c) : cal(nums[j--], a, b, c);
            } else {
                res[idx++] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c) ? cal(nums[j--], a, b, c) : cal(nums[i++], a, b, c);
            }
        }
        return res;
    }
    int cal(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};

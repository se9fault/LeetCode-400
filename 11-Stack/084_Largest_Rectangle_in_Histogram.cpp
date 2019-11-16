/*
Given n non-negative integers representing the histogram's bar height where the
width of each bar is 1, find the area of largest rectangle in the histogram.

Example:
Input: [2,1,5,6,2,3]
Output: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 0)
		return 0;
	int maxArea = 0;
	std::stack<int> stack;
	// 数组的每个数进入单调栈，该单调栈找左侧右侧最近的比其小的数，
    // 代表着这个数能够向左向右扩展多远
	for (int i = 0; i < heights.size(); i++) {
		// 维持栈内从从底到顶从小到大。如果当前值比栈顶值小，则弹出所有比当前值大的值。
		while (!stack.empty() && heights[i] <= heights[stack.top()]) {
			int j = stack.top(); // 弹出的数为 j，右侧为 i（导致弹出者）
			stack.pop();
			int k = stack.empty() ? -1 : stack.top(); // 若栈空，则左侧为null
			int curArea = (i - k - 1) * heights[j];
			maxArea = std::max(maxArea, curArea);
		}
		stack.push(i);
	}
	// 数组已经没有数了，但是栈内还有未弹出的值
	while (!stack.empty()) {
		int j = stack.top();
		stack.pop();
		int k = stack.empty() ? -1 : stack.top();
		int curArea = (heights.size() - k - 1) * heights[j];
		maxArea = std::max(maxArea, curArea);
	}
	return maxArea;
    }
};

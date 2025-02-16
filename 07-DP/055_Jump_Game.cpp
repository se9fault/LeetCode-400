/*
Given an array of non-negative integers, you are initially positioned at the
first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump
length is 0, which makes it impossible to reach the last index.
*/

enum index {good, bad, unknown};

// here the solution is DP, O(N^2), but actually greedy works with O(N)
class Solution {
public:
    vector<int> mem;
    bool canJump(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            mem.push_back(unknown);
        }
        mem.push_back(good);
        return canJumpFromPos(nums, 0);
    }

    // jump from pos to the end
    bool canJumpFromPos(vector<int>& nums, int pos) {
        if (mem[pos] != unknown) {
            return mem[pos] == good ? true : false;
        }
        int furthest = std::min(pos + nums[pos], (int)nums.size() - 1);
        for (int nextPos = pos + 1; nextPos <= furthest; nextPos++) {
            if (canJumpFromPos(nums, nextPos)) {
                mem[pos] = good;
                return true;
            }
        }
        mem[pos] = bad;
        return false;
    }
};

// greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0, n = nums.size();
        for (int i = 0; i <= furthest && i < n; ++i) {
            furthest = max(furthest, i + nums[i]);
        }
        return furthest >= n - 1;
    }
};

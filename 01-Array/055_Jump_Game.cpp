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

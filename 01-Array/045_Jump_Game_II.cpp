// greedy here
class Solution {
public:
    int jump(vector<int>& nums) {
        int count(0), curEnd(0), curFarthest(0);
        for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd) {
                ++count;
                curEnd = curFarthest;
                if (curEnd >= nums.size() - 1)
                    break;
            }
        }
        return count;
    }
};
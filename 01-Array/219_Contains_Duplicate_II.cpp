class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> nmap; 
        // stores (num, the last position num appeared)
        for (int i = 0; i < nums.size(); ++i) {
            if (nmap.find(nums[i]) == nmap.end())
                nmap[nums[i]] = i;
            else if (i - nmap[nums[i]] <= k)
                return true;
            else
                nmap[nums[i]] = i;
        }
        return false;
    }
};
/*
Given a non-empty array of integers, every element appears three times except
for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it
without using extra memory?

Example 1:
Input: [2,2,3,2]
Output: 3

Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
    	vector<int> arr(32); // Made a array contain 32 elements.
    	int n = nums.size(), num;
    	for (int i = 0; i < n; ++i) {
    		num = nums[i];
    		for (int j = 31; j >= 0; --j) {
    			arr[j] += num & 1; // Find the last digit.
    			num >>= 1;
    			if (!num)
    				break;
    	    }
        }
        int ans = 0;
        for (int j = 31; j >= 0; --j)
        {
            num = arr[j] % 3; // "3" represents k times.
            if (num)
                ans += 1 << (31 - j);
        }
        return ans;
    }
};

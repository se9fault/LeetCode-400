/*
Given a non negative integer number num. For every numbers i in the range
0 ≤ i ≤ num calculate the number of 1's in their binary repansentation and
return them as an array.

Example 1:    Input: 2    Output: [0,1,1]
Example 2:    Input: 5    Output: [0,1,1,2,1,2]

Follow up:
1. It is very easy to come up with a solution with run time
O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
single pass?
2. Space complexity should be O(n).
3. Can you do it like a boss? Do it without using any builtin function like
__builtin_popcount in c++ or in any other language.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return {0};
        vector<int> ans{0, 1};
        int k = 2, i = 2;
        while (i <= num) {
            for (i = pow(2, k - 1); i < pow(2, k); ++i) {
                if (i > num)
                    break;
                int t = (pow(2, k) - pow(2, k - 1)) / 2;
                if (i < pow(2, k - 1) + t)
                    ans.push_back(ans[i - t]);
                else
                    ans.push_back(ans[i - t] + 1);
            }
            ++k;
        }
        return ans;
    }
};

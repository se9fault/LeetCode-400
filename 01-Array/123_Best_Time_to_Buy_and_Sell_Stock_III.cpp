/*
Say you have an array for which the ith element is the price of a given stock
on day i.

Design an algorithm to find the maximum profit. You may complete at most *TWO*
transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you
must sell the stock before you buy again).

Solution: Clearly a DP problem.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[2][4] = {INT_MIN, 0, INT_MIN, 0};
        // row num: days.  
        //     dp[i][] only relies on dp[i-1][], so store 2 days is enough
        // col num: state.
        //     0: 1 buy   1: 1 buy 1 sell   2: 2 buy 1 sell   3: 2 buy 2 sell
        int n = prices.size(), cur = 0, next = 1;

        for (int i = 0; i < n; ++i) {
            dp[next][0] = max(dp[cur][0], -prices[i]); // buy stock costs money
            dp[next][1] = max(dp[cur][1], dp[cur][0] + prices[i]);
            dp[next][2] = max(dp[cur][2], dp[cur][1] - prices[i]);
            dp[next][3] = max(dp[cur][3], dp[cur][2] + prices[i]);
            // if we reverse the calculating order, we only need to use 4
            // variables
            swap(next, cur);
        }
        return max(dp[cur][1], dp[cur][3]);
    }
};

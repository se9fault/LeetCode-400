/*
Say you have an array for which the i-th element is the price of a given stock
on day i.

Design an algorithm to find the maximum profit. You may complete at most k
transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell
the stock before you buy again).
*/

class Solution {
public:
    int maxProfit_all(vector<int> &prices) {
        int n = prices.size();
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i-1]) {
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }

    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k >= n/2) {
            return maxProfit_all(prices);
        }

        // x: x txns used already. dp[i][] only depends on dp[i-1][], so only use two.
        // y: days. actually here we can also cut down variable size.
        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        for (int t = 1; t <= k; t++) {
            int cur_max = INT_MIN;
            for (int i = 0; i < n; i++) {
                // calculating dp[t%2][] based on dp[(t-1)%2][]
                dp[t%2][i+1] = max(dp[(t+1)%2][i+1], max(dp[t%2][i], prices[i] + cur_max));
                cur_max = max(cur_max, dp[(t+1)%2][i] - prices[i]);
            }
        }
        return dp[k%2][n];
    }
};
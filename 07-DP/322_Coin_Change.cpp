/*
You are given coins of different denominations and a total amount of money
amount. Write a function to compute the fewest number of coins that you need to
make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /* f(n) = 0, n = 0
                  min()
        */
        int m = coins.size();
        vector<int> dp(amount + 1, amount + 1); // a large enough value
        dp[0] = 0; // needed. or else how would k=1 start constructing?
        for (int i = 0; i <= amount; ++i) {
            for (int j = 0; j < m; ++j) {
                if (coins[j] <= i) {
                    // int k = i / coins[j];
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    // try to use 1 coins[j] to reduce dp[i]
                    // why not use multiple?
                    //   With original optimal dp[i-coins[j]], add 1 coin would
                    //   be optimal, but dp[i-k*coins[j]] + k is not.
                    //   You should let dp[i-coins[j]] decide how much coins[j]
                    //   it need to use.
                }
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};

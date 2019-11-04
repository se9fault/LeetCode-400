/*
Say you have an array for which the ith element is the price of a given stock
on day i.

Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (ie, buy one and sell one share of the stock multiple
times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must
    sell the stock before you buy again).

    After you sell your stock, you cannot buy stock on next day. (ie, cooldown
    1 day)

Solution: DP again.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int i, n = prices.size();
        int result = 0;
        vector<int> buy(n, 0), sell(n, 0);
        // buy[i]:  the max profit when you buy the stock at day i.
        // sell[i]: the max profit when you sell the stock at day i. 
        buy[0] = -prices[0];
        for (i = 1; i < n; ++i) {
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
            //     buy on day i-1, see it today    reverse the sell yesterday, sell it today
            if (result < sell[i])
                result = sell[i];
            if (i == 1)
                buy[i] = buy[0] + prices[0] - prices[1];
            else
                buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
                //   sold it before cooldown, buy it    reverse the buy yesterday, buy it today
        }
        return result;
    }   
};
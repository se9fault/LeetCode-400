/*
Say you have an array for which the ith element is the price of a given stock 
on day i.

If you were only permitted to complete at most one transaction (i.e., buy one 
and sell one share of the stock), design an algorithm to find the maximum 
profit.

Solution: foe each day, check twice: what is the lowest price I can get (for 
future), and what is the maximum profit I can get if I sell today.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice(INT_MAX), maxProfit(0);
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};
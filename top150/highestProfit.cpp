/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice=INT_MAX;
        int maxProfit=0;
        for(int price : prices){
            if(price < lowestPrice){
                lowestPrice = price;
            }
            int profit = price - lowestPrice;
            if(profit > maxProfit)
            {
                maxProfit = profit;
            }
        }
            return maxProfit;
    }
};

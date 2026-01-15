class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0] , profit = 0;
        for(int i=1;i<prices.size();i++){
            profit = max(profit , prices[i] - minimum);
            minimum = (prices[i] > minimum) ? minimum : prices[i];
        }
        return profit;

    }
};
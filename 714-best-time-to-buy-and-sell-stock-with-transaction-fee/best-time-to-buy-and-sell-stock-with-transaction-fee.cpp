class Solution {
public:
    int maxProfitHelper(int day , bool hasBought , int fee , const vector<int> &prices , vector<vector<int>> &dp){
        if(day == prices.size())return 0;
        if(dp[day][hasBought] != -1)return dp[day][hasBought];
        if(hasBought){
            int sellingToday = prices[day] - fee + maxProfitHelper(day + 1, false , fee , prices , dp);
            int sellingAnotherDay = maxProfitHelper(day + 1, hasBought , fee , prices , dp);
            return dp[day][hasBought] = max(sellingToday , sellingAnotherDay);
        }
        int buyingToday = maxProfitHelper(day + 1, true , fee , prices , dp) - prices[day];
        int notBuying = maxProfitHelper(day + 1 , hasBought , fee , prices , dp);
        return dp[day][hasBought] = max(buyingToday , notBuying);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size() , vector<int>(2 , -1));
        return maxProfitHelper(0 , false , fee , prices , dp);
    }
};
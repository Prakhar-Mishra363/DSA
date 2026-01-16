class Solution {
public:
    int maxProfitHelper(int day , bool hasBought , const vector<int> &prices , vector<vector<int>> &dp){
        if(day >= prices.size())return 0;
        if(dp[day][hasBought] != -1)return dp[day][hasBought];
        if(hasBought){
            int sellingToday = prices[day] + maxProfitHelper(day + 2 , false , prices , dp);
            int sellingAnotherDay = maxProfitHelper(day + 1 , hasBought , prices , dp);
            return dp[day][hasBought] = max(sellingToday , sellingAnotherDay);
        }
        int buyingToday = maxProfitHelper(day + 1 , true , prices , dp) - prices[day];
        int notBuyingToday = maxProfitHelper(day + 1 , hasBought , prices , dp);
        return dp[day][hasBought] = max(buyingToday , notBuyingToday);
    }
    int maxProfit(vector<int>& prices) {
        /*
        // recursion + memoization
        int day=0;
        vector<vector<int>>dp(prices.size() , vector<int>(2 , -1));
        return maxProfitHelper(day , false , prices , dp);
        */
        int n=prices.size();
        vector<vector<int>>dp(n+2 , vector<int>(2 , 0));
        for(int day=n-1 ; day>=0 ; day--){
            for(int hasBought=1 ; hasBought>=0 ; hasBought--){
                if(hasBought){
                    int sellingToday = prices[day] + dp[day + 2][0];
                    int sellingAnotherDay = dp[day + 1][hasBought];
                    dp[day][hasBought] = max(sellingToday , sellingAnotherDay);
                }else{
                    int buyingToday = dp[day + 1][1]- prices[day];
                    int notBuyingToday = dp[day + 1][hasBought];
                    dp[day][hasBought] = max(buyingToday , notBuyingToday);
                }
            }
        }
        return dp[0][0];
    }
};
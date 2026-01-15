class Solution {
public:
    int maxProfitHelper(int idx , bool hasBought , const vector<int> &prices , vector<vector<int>> &dp){
        //base case -> we reached the last day
        if(idx == prices.size()-1){
            //if boughtStockPrice == 0 => means we need to buy the stock so we simply return 0
            if(hasBought)return prices[idx];
            /*
            we have some stock to sell, so if boughtStockPrice>prices[idx] we 
            return the profit as 0 => we'll get loss if we sell,
            else simply return the profit
            */
            return 0;
        }
        //dp memoization
        if(dp[idx][hasBought] != -1)return dp[idx][hasBought];
        //if current bought stock's value is greater than last days stocks value
        //here boughtStockPrice>0 so we have bought.
        if(hasBought ){
            //case 1 -> we try to sell it on another day regardless of today's stock price
            int sellOnAnotherDay = maxProfitHelper(idx + 1 , hasBought , prices , dp);
            //case 2nd -> if today's stock price is greater than boughtStockPrice then we sell it today and try to buy the stock another day else 0
            int sellingStock = prices[idx] + maxProfitHelper(idx + 1 , false , prices , dp) ;
            return dp[idx][hasBought] = max(sellOnAnotherDay , sellingStock);
        }
        //here boughtStockPrice = 0 , we buy the stock on that day and try to sell it on the upcoming days
        int stockIsBought = maxProfitHelper(idx + 1 , true , prices , dp) - prices[idx];
        //case 3 -> we buy today's stock discarding the current bought stock to get the profit
        int doNotBuy = maxProfitHelper(idx + 1 , false , prices , dp);
        return dp[idx][hasBought] = max(stockIsBought , doNotBuy);

    }
    int maxProfit(vector<int>& prices) {
        int maxColumn = *max_element(prices.begin() , prices.end());
        /*
        //recursion + memoization
        vector<vector<int>>dp(prices.size() + 1 , vector<int>(2 , -1));
        return maxProfitHelper(0 , false, prices , dp);
        */
        //tabulation
        int n = prices.size();
        vector<vector<int>> dp(prices.size() , vector<int>(2 , 0));
        // vector<int>dp(maxColumn+1 , 0) , tmp(maxColumn+1 , 0);
        // base case
        dp[n-1][0] = 0;
        dp[n-1][1] = prices[n-1];
        for(int idx = n-2 ; idx>=0 ; idx--){
            for(int hasBought=0 ; hasBought<=1 ; hasBought++){
                if(hasBought ){
                    //case 1 -> we try to sell it on another day regardless of today's stock price
                    int sellOnAnotherDay = dp[idx + 1][hasBought];
                    //case 2nd -> if today's stock price is greater than boughtStockPrice then we sell it today and try to buy the stock another day else 0
                    int sellingStock = prices[idx] + dp[idx + 1][0];
                    dp[idx][hasBought] = max(sellOnAnotherDay , sellingStock);
                }else{
                    int stockIsBought = dp[idx + 1][1]- prices[idx];
                    int doNotBuy = dp[idx + 1][0];
                    dp[idx][hasBought] = max(stockIsBought , doNotBuy);
                }
            }
        }
        // for(auto a : dp){
        //     for(auto b : a){
        //         cout<<b<<" ";
        //     }cout<<endl;
        // }
        return dp[0][0];

    }
};
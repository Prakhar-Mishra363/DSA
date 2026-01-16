class Solution {
public:
    int maxProfitHelper(int day , int cap , const vector<int> &prices , vector<vector<int>> &dp){
        //base case
        if(cap == 0 || day == prices.size())return dp[day][cap] = 0;
        //we need to sell the stock
        if(cap % 2 == 1){
            int sellAnotherDay = maxProfitHelper(day + 1 , cap , prices , dp);
            int stockIsSold = maxProfitHelper(day + 1 , cap-1 , prices , dp) + prices[day];
            return dp[day][cap] = max(sellAnotherDay , stockIsSold);
        }
        int buyTheStock = maxProfitHelper(day + 1  , cap -1 , prices , dp) - prices[day];
        int doNotBuy = maxProfitHelper(day + 1  , cap , prices , dp);
        return dp[day][cap] = max(buyTheStock , doNotBuy);
    }
    int maxProfit(int k, vector<int>& prices) {
        /*
        int day = 0;
        bool hasBought = false;
        vector<vector<int>>dp(prices.size() + 1, vector<int>(2*k + 1, -1));
        int result = maxProfitHelper(day , k*2  , prices , dp);
        for(auto a : dp){
            for(auto b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return result;
        */
        vector<int>dp(2*k + 1 , 0) , tmp(2*k + 1 , 0);
        int n=prices.size();
        for(int day = n-1 ; day>=0 ; day--){
            for(int cap=1 ; cap<=2*k ; cap++){
                if(cap % 2 == 1){
                    int sellAnotherDay = dp[cap];
                    int stockIsSold = dp[cap-1] + prices[day];
                    tmp[cap] = max(sellAnotherDay , stockIsSold);
                }else{
                    int buyTheStock = dp[cap - 1] - prices[day];
                    int doNotBuy = dp[cap];
                    tmp[cap] = max(buyTheStock , doNotBuy);
                }
            }
            dp = tmp;
        }
        
        return dp[2*k];
    }
};
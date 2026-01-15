class Solution {
public:
    int maxProfitHelper(int day , bool hasBought , int numberOfTrans , const vector<int> &prices , vector<vector<vector<int>>> &dp){
        //base cases
        //1. two transactions have been made
        if(numberOfTrans == 2 || day == prices.size())return 0;
        //2. two transaction has not been made yet and we are at the last day
        if(dp[day][hasBought][numberOfTrans] != -1)return dp[day][hasBought][numberOfTrans];
        if(hasBought){
            //selling the stock today
            int soldAnotherDay = maxProfitHelper(day + 1 , hasBought , numberOfTrans , prices , dp);
            //selling the stock => no. of transactions will be increased , state of hasBought will bw changed
            int hasBeenSold = prices[day] + maxProfitHelper(day + 1 , false , numberOfTrans + 1 , prices , dp);
            return dp[day][hasBought][numberOfTrans] = max(soldAnotherDay , hasBeenSold);
        }
        int buyingToday = maxProfitHelper(day + 1 , true , numberOfTrans , prices , dp) - prices[day];
        int notBuyingToday = maxProfitHelper(day + 1 , hasBought , numberOfTrans , prices , dp);
        return dp[day][hasBought][numberOfTrans] = max(buyingToday , notBuyingToday);
    }
    int maxProfit(vector<int>& prices) {
        /*
        //recursion + memoization
        vector<vector<vector<int>>>dp(prices.size() , 
                            vector<vector<int>>(2 , 
                            vector<int>(3 , -1)));
        int result = maxProfitHelper(0 , false , 0 , prices , dp);
        for(auto a:dp){
            for(auto b:a){
                for(auto c:b){
                    cout<<c<<" ";
                }cout<<endl;
            }cout<<endl;
        }
        return result;
        */
        //tabulation
        vector<vector<int>>dp(2,vector<int>(3 , 0)) , tmp(2,vector<int>(3 , 0));
        int n = prices.size();
        for(int day = n-1 ; day>=0 ; day--){
            for(int hasBought=1 ; hasBought>=0 ; hasBought--){
                for(int numberOfTrans=1 ; numberOfTrans>=0; numberOfTrans--){
                    if(hasBought){
                        //selling the stock today
                        int soldAnotherDay = dp[hasBought][numberOfTrans];
                        //selling the stock => no. of transactions will be increased , state of hasBought will bw changed
                        int hasBeenSold = prices[day] + dp[0][numberOfTrans + 1];
                        tmp[hasBought][numberOfTrans] = max(soldAnotherDay , hasBeenSold);
                    }else{
                        int buyingToday = dp[1][numberOfTrans] - prices[day];
                        int notBuyingToday = dp[hasBought][numberOfTrans];
                        tmp[hasBought][numberOfTrans] = max(buyingToday , notBuyingToday);
                    }
                }
                dp = tmp;
            }
        }
        return dp[0][0];
        
    }
};
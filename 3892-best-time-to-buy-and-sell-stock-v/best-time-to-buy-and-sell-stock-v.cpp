class Solution {
public:
    //transactionType 0 for a transaction to make of normal or shortselling one
    long long maximumProfitHelper(int day , int transactions ,int transactionType , const vector<int> &prices , vector<vector<vector<long long>>> &dp){
        //base cases (same old)
        if(day == prices.size() || transactions == 0){
            if(transactionType)return -1e9;
            return 0;
        }
        //a type of transaction has been made
        if(dp[day][transactions][transactionType] != -1)return dp[day][transactions][transactionType];
        if(transactionType){
            //normal transaction is being made
            if(transactionType == 1){
                //selling the stock and setting the transactionType to nothing to make normal or short selling again
                long long sellingToday = maximumProfitHelper(day + 1 , transactions-1 , 0 , prices , dp) + prices[day];
                //selling any other day
                long long sellingAnotherDay = maximumProfitHelper(day + 1 , transactions , transactionType , prices , dp);
                return dp[day][transactions][transactionType] = max(sellingToday , sellingAnotherDay);
            }else{
                //short selling transaction is being made
                long long buyingToday = maximumProfitHelper(day + 1 , transactions-1 , 0 , prices , dp) - prices[day];
                //buying another day
                long long buyingAnotherDay = maximumProfitHelper(day + 1 , transactions , transactionType , prices , dp);
                return dp[day][transactions][transactionType] = max(buyingToday , buyingAnotherDay);
            }

        }
        //making normal transaction
        long long buying = maximumProfitHelper(day + 1 , transactions-1 , 1 , prices , dp) - prices[day];
        long long notBuying = maximumProfitHelper(day + 1 , transactions , transactionType , prices , dp);
        //making short selling transaction
        long long shortSelling = maximumProfitHelper(day + 1 , transactions-1 , 2 , prices , dp) + prices[day];
        return dp[day][transactions][transactionType] = max(max(buying ,notBuying) , shortSelling);

    }
    //requires a state for indicating normal transaction and short selling transaction
    long long maximumProfit(vector<int>& prices, int k) {
        int day = 0;
        int transactions = 2 * k;
        vector<vector<vector<long long>>>dp(prices.size() , vector<vector<long long>>(2*k + 1 , vector<long long>(3 , -1)));
        return maximumProfitHelper(day , transactions , 0 , prices , dp);
    }
};
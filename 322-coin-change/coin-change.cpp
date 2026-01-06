class Solution {
public:
    int coinChangeHelper(int idx, int currAmount, const vector<int> &coins,vector<vector<int>> &dp){
        if(idx == coins.size()-1){
            if(currAmount % coins[idx] == 0)return dp[idx][currAmount] = currAmount/coins[idx];
            return 1e9;
        }
        if(dp[idx][currAmount] != -1)return dp[idx][currAmount];
        int left = 0 + coinChangeHelper(idx + 1, currAmount, coins,dp);
        int picked = (coins[idx] <= currAmount) ? 1 + coinChangeHelper(idx , currAmount - coins[idx], coins,dp) : 1e9;
        return dp[idx][currAmount] = min(left, picked);
    }
    int coinChange(vector<int>& coins, int amount) {
        /* -> meoization + recusion approach
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1, -1));
        int result = coinChangeHelper(0,amount, coins,dp);
        for(auto a : dp){
            for(auto b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return (result == 1e9) ? -1 : result;
        */
        //Tabulation
        int n = coins.size();
        //first base case 
        /*
            simply if ((amount - coins[i]) % coins[n-1] == 0) then dp[n-1][amount - coins[i]] = (amount - coins[i]) / coins[n-1] {i = 0 to n-2}
        */
        vector<int>dp(amount+1, 0);
        for(int i=0 ; i<=amount ; i++){
            dp[i] = (i % coins[n-1] == 0) ? i/coins[n-1] : 1e9;
        }

        for(int idx = n-2 ; idx>=0 ;idx--){
            vector<int>temp(amount+1,0);
            for(int currAmount = 0 ; currAmount<= amount ; currAmount++){
                int left = 0 + dp[currAmount];
                int picked = (coins[idx] <= currAmount) ? temp[currAmount - coins[idx]] + 1 : 1e9;
                temp[currAmount] = min(left , picked);
            }
            dp = temp;
        }
        // for(auto a : dp){
        //     cout<<a<<" ";
        // }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
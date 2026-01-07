class Solution {
public:
    int changeHelper(int idx, int currAmount, const vector<int> &coins, vector<vector<int>> &dp){
        // if(currAmount == 0)return dp[idx][currAmount] = 1;
        if(idx == coins.size()-1){
            if((currAmount % coins[idx]) == 0)return dp[idx][currAmount] = 1;
            else return dp[idx][currAmount] = 0;
        }
        if(dp[idx][currAmount] != -1)return dp[idx][currAmount];
        int picked = (currAmount >= coins[idx]) ? changeHelper(idx ,currAmount - coins[idx], coins, dp ) : 0 ;
        int left = changeHelper(idx + 1,currAmount , coins, dp);
        return dp[idx][currAmount] = (picked + left);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        /*
        // -> memoization + recursion 
        vector<vector<int>>dp(n , vector<int>(amount+1,-1));
        int result = changeHelper(0,amount,coins,dp);
        for(auto a : dp){
            for(auto b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return result;
        */

        /*
        -> Tabulation 
        vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));
        for(int i=0;i<=amount;i++){
            dp[n-1][i] = (i % coins[n-1] == 0) ? 1 : 0;
        }
        for(int idx=n-2; idx>= 0; idx--){
            for(int currAmount=0; currAmount<= amount; currAmount++){
                unsigned long long picked = (currAmount >= coins[idx]) ? dp[idx][currAmount - coins[idx]] : 0 ;
                unsigned long long left = dp[idx + 1][currAmount];
                dp[idx][currAmount] = (picked + left);
            }
        }
        return dp[0][amount];
        */
        //space optimization in tabulation
        vector<unsigned long long>dp(amount + 1, 0), temp(amount + 1, 0);
        for(int i=0;i<=amount;i++){
            dp[i] = (i % coins[n-1] == 0) ? 1 : 0; 
        }
        for(int idx = n-2; idx>=0 ; idx--){
            for(int currAmount = 0 ; currAmount<=amount ; currAmount++){
                unsigned long long picked = (currAmount >= coins[idx]) ? temp[currAmount - coins[idx]] : 0 ;
                unsigned long long left = dp[currAmount];
                temp[currAmount] = (picked + left);
            }
            dp = temp;
        }
        return dp[amount];
    }
};
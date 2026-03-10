class Solution {
public:
    const int MOD = 1e9+7;
    int helper(int remainingZeros , int remainingOnes , bool wasOne , int limit , vector<vector<vector<long long>>> &dp){
        if(remainingZeros==0 && remainingOnes==0)return 1;
        if(dp[wasOne][remainingZeros][remainingOnes] != -1)return dp[wasOne][remainingZeros][remainingOnes];
        long long ways=0;
        if(wasOne){
            for(int zero=1 ; zero<=min(remainingZeros , limit) ; zero++){
                ways += helper(remainingZeros-zero , remainingOnes , false , limit , dp);
                ways %= MOD;
            }
        }else{
            for(int ones=1 ; ones<=min(remainingOnes , limit) ; ones++){
                ways += helper(remainingZeros , remainingOnes-ones , true , limit , dp);
                ways %= MOD;
            }
        }
        return dp[wasOne][remainingZeros][remainingOnes]  = ways;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>>dp(2 , vector<vector<long long>>(zero+1 , vector<long long>(one+1 , 0)));
        // long long zero_in_start = helper(zero , one , true , limit , dp);
        // long long one_in_start = helper(zero , one , false , limit , dp);
        dp[0][0][0]=dp[1][0][0]=1;
        for(int remainingZeros=0 ; remainingZeros<=zero ; remainingZeros++){
            for(int remainingOnes=0 ; remainingOnes<=one ; remainingOnes++){
                long long ways = 0;
                if(!remainingZeros && !remainingOnes)continue;
                for(int len=1 ; len<=min(remainingZeros,limit) ; len++){
                    ways = (ways + dp[1][remainingZeros-len][remainingOnes])%MOD;
                }
                dp[0][remainingZeros][remainingOnes]=ways;
                ways=0;
                for(int ones=1 ; ones<=min(remainingOnes , limit) ; ones++){
                    ways = ways + dp[0][remainingZeros][remainingOnes-ones];
                    ways %= MOD;
                }
                dp[1][remainingZeros][remainingOnes]=ways;
            }
        }
        return (dp[0][zero][one] + dp[1][zero][one]) % MOD;
    }
};
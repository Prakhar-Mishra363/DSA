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
        vector<vector<vector<long long>>>dp(2 , vector<vector<long long>>(zero+1 , vector<long long>(one+1 , -1)));
        long long zero_in_start = helper(zero , one , true , limit , dp);
        long long one_in_start = helper(zero , one , false , limit , dp);
        return (zero_in_start + one_in_start) % MOD;
    }
};
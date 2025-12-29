class Solution {
public:
    // long long fact(int n){
    //     if(n <= 1)return 1;
    //     // int nMinus1 = 1;
    //     long long result = 1;
    //     for(int i=2;i<=n;i++){
    //         result = result * i;
    //     }
    //     return result;
    // }
    // int climbStairsHelper(int n,vector<int> &dp){
    //     if(dp[n] != -1)return dp[n];
    //     return dp[n] = climbStairsHelper(n-1,dp) + climbStairsHelper(n-2,dp);
    // }
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int nMinus1 = 2;
        int nMinus2 = 1;
        int distinctWaysToClimb = 0;
        for(int i=3;i<=n;i++){
            distinctWaysToClimb = nMinus1 + nMinus2;
            nMinus2 = nMinus1;
            nMinus1 = distinctWaysToClimb;
        }
        return distinctWaysToClimb;
    }
};
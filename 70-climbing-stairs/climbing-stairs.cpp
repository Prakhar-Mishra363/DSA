class Solution {
public:
    int climbStairsHelper(int currentStair , int destStair , vector<int> &dp){
        if(currentStair == destStair)return 1;
        if(currentStair > destStair)return 0;
        if(dp[currentStair] != -1)return dp[currentStair];
        int jump_one=climbStairsHelper(currentStair+1 , destStair , dp);
        int jump_two=climbStairsHelper(currentStair+2 , destStair , dp);
        return dp[currentStair] = jump_one + jump_two;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climbStairsHelper(0 , n , dp);
    }
};
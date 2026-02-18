class Solution {
public:
    int climbStairsHelper(int curr , int dest , vector<int> &cost , vector<int> &dp){
        if(curr==dest)return 0;
        if(dp[curr] != -1)return dp[curr];
        int jump_one=(curr+1<=dest) ? cost[curr] + 1 + climbStairsHelper(curr+1 , dest , cost , dp) : 1e6;
        int jump_two=(curr+2<=dest) ? cost[curr+1] + 4 + climbStairsHelper(curr+2 , dest , cost , dp) : 1e6;
        int jump_three=(curr+3<=dest) ? cost[curr+2] + 9 + climbStairsHelper(curr+3 , dest , cost , dp) : 1e6;
        return dp[curr] = min(jump_one , min(jump_two , jump_three));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return climbStairsHelper(0 , n , costs , dp);
    }
};
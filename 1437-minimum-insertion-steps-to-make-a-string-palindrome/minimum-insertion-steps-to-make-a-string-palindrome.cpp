class Solution {
public:
    int minInsertionsHelper(int start , int end , const string &s , vector<vector<int>> &dp){
        if(start >= end)return 0;
        if(dp[start][end] != -1)return dp[start][end];
        if(s[start] == s[end]){
            return dp[start][end] = minInsertionsHelper(start+1 , end-1 , s , dp);
        }
        return dp[start][end] = 1 + min (minInsertionsHelper(start , end-1 , s ,dp) , 
                minInsertionsHelper(start + 1, end , s , dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return minInsertionsHelper(0 , n-1 , s , dp);
    }
};
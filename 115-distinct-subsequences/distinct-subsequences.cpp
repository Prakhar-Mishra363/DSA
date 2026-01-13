class Solution {
public:
    int numDistinctHelper(int idx1, int idx2 , string &s , string &t , vector<vector<int>> &dp){
        if(idx2 == t.size())return 1;
        if(idx1 == s.size())return 0;
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        if(s[idx1] == t[idx2]){
            int goingAhead = numDistinctHelper(idx1 + 1 , idx2 + 1 , s ,t , dp) ;
            int checkingForAnotherOne = numDistinctHelper(idx1 + 1 , idx2 , s , t , dp);
            return dp[idx1][idx2] = (goingAhead + checkingForAnotherOne); 
        }
        return dp[idx1][idx2] = numDistinctHelper(idx1 + 1 , idx2 , s ,t , dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size() , vector<int>(t.size() , -1));
        return numDistinctHelper(0 , 0 , s , t , dp);
    }
};
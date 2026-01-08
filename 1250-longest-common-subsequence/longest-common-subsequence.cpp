class Solution {
public:
    int longestCommonSubsequenceHelper(int idx1, int idx2, const string &text1, const string &text2 , vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0)return 0;
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + longestCommonSubsequenceHelper(idx1-1 , idx2-1 , text1 , text2 , dp);
        }
        return dp[idx1][idx2] = max(longestCommonSubsequenceHelper(idx1-1 , idx2 , text1 , text2 , dp) , 
                longestCommonSubsequenceHelper(idx1 , idx2-1 , text1 , text2 , dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() , m = text2.length();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return longestCommonSubsequenceHelper(text1.length() - 1,text2.length() -1 ,text1,text2, dp);
    }
};
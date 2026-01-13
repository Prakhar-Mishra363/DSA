class Solution {
public:
    int minDistanceHelper(int idx1 , int idx2 , const string &word1 , const string &word2 , vector<vector<int>> &dp){
        if(idx1 == word1.size())return (word2.substr(idx2)).size();
        if(idx2 == word2.size())return (word1.substr(idx1)).size();
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        if(word1[idx1] == word2[idx2]){
            return dp[idx1][idx2] = minDistanceHelper(idx1 + 1 , idx2 + 1 , word1 , word2 , dp);
        }
        int replaced = minDistanceHelper(idx1 + 1, idx2 + 1 , word1 , word2 , dp);
        int inserted = minDistanceHelper(idx1 , idx2 + 1 , word1 , word2 , dp);
        int erased = minDistanceHelper(idx1 + 1 , idx2 , word1 , word2 , dp);
        return dp[idx1][idx2] =  1 + min(replaced , min(inserted , erased));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() , vector<int>(word2.size() , -1));
        return minDistanceHelper(0 , 0 , word1 , word2 , dp);
    }
};
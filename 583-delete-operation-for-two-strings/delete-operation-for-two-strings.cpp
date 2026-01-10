class Solution {
public:
    int minDistanceHelper(int len1 , int len2 , const string &word1 , const string &word2 , vector<vector<int>> &dp){
        //base cases
        //when len1 == word1's length => we require to delete (word2.length() - len2) characters from word2
        if(len1 == word1.size())return (word2.length() - len2);
        //when len2 == word2's length =? we require to delete (word1.length() -len1) characters from word1
        if(len2 == word2.size())return (word1.length() - len1);

        if(dp[len1][len2] != -1)return dp[len1][len2];
        if(word1[len1] == word2[len2]){
            return minDistanceHelper(len1 + 1, len2 + 1, word1 , word2 , dp);
        }
        int delFromWord1 = minDistanceHelper(len1 + 1 , len2 , word1 , word2 , dp);
        int delFromWord2 = minDistanceHelper(len1 , len2 + 1 , word1 , word2 , dp);
        return dp[len1][len2] = 1 + min(delFromWord1 , delFromWord2);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() , vector<int>(word2.size() , -1));
        return minDistanceHelper(0 , 0 , word1 , word2 , dp);
    }
};
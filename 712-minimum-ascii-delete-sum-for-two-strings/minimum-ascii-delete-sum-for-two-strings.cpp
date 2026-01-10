class Solution {
public:
    int minimumDeleteSumHelper(int len1 , int len2 , const string &word1 , const string &word2 , vector<vector<int>> &dp){
        //base cases
        //when len1 == word1's length => we require to delete (word2.length() - len2) characters from word2
        if(len1 == word1.size()){
            int sum = 0;
            for(int i=len2 ; i<word2.size() ; i++){
                sum += (int)word2[i];
            }
            return dp[len1][len2] =  sum;
        }
        //when len2 == word2's length =? we require to delete (word1.length() -len1) characters from word1
        if(len2 == word2.size() ){
            int sum = 0;
            for(int i=len1 ; i<word1.size() ; i++){
                sum += (int)word1[i];
            }
            return dp[len1][len2] = sum;
        }

        if(dp[len1][len2] != -1)return dp[len1][len2];
        if(word1[len1] == word2[len2]){
            return dp[len1][len2] = minimumDeleteSumHelper(len1 + 1, len2 + 1, word1 , word2 , dp);
        }
        int delFromWord1 = minimumDeleteSumHelper(len1 + 1 , len2 , word1 , word2 , dp) + (int)word1[len1];
        int delFromWord2 = minimumDeleteSumHelper(len1 , len2 + 1 , word1 , word2 , dp) + (int)word2[len2];
        return dp[len1][len2] = min(delFromWord1 , delFromWord2);
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size() + 1 , vector<int>(s2.size() + 1 , -1));
        int result = minimumDeleteSumHelper(0 , 0 , s1 , s2 , dp);
        return result;

    }
};
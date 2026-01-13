class Solution {
public:
    int minDistanceHelper(int idx1 , int idx2 , const string &word1 , const string &word2 , vector<vector<int>> &dp){
        if(idx1 == word1.size())return dp[idx1][idx2] = (word2.substr(idx2)).size();
        if(idx2 == word2.size())return dp[idx1][idx2] = (word1.substr(idx1)).size();
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
        /* (recursion + memoization)
        vector<vector<int>>dp(word1.size() + 1 , vector<int>(word2.size() + 1 , -1));
        int result = minDistanceHelper(0 , 0 , word1 , word2 , dp);
        for(auto &a : dp){
            for(auto &b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return result;
        */
        /*
        //tabulation
        vector<vector<int>>dp(word1.size() + 1 , vector<int>(vector<int>(word2.size() + 1 , 0)));
        for(int i=0;i<=word1.size();i++){
            dp[i][word2.size()] = word1.size()-i;
        }
        for(int i=0; i<=word2.size() ; i++){
            dp[word1.size()][i] = word2.size()-i;
        }
        for(int idx1 = word1.size()-1 ; idx1>= 0 ; idx1--){
            for(int idx2=word2.size()-1 ; idx2>=0 ; idx2--){
                if(word1[idx1] == word2[idx2]){
                    dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1];
                }else{
                    int replaced = dp[idx1 + 1][idx2 + 1];
                    int inserted = dp[idx1][idx2 + 1];
                    int erased = dp[idx1 + 1][idx2];
                    dp[idx1][idx2] =  1 + min(replaced , min(inserted , erased));
                }
            }
        }
        return dp[0][0];
        */
        //space optimization for tabulation
        vector<int>dp(word2.size()+1 , 0), tmp(word2.size() + 1 , 0);
        for(int i=0; i<=word2.size() ; i++){
            dp[i] = word2.size()-i;
        }
        for(int idx1 = word1.size()-1 ; idx1>= 0 ; idx1--){
            tmp[word2.size()] = word1.size()-idx1;
            for(int idx2=word2.size()-1 ; idx2>=0 ; idx2--){
                if(word1[idx1] == word2[idx2]){
                    tmp[idx2] = dp[idx2 + 1];
                }else{
                    int replaced = dp[idx2 + 1];
                    int inserted = tmp[idx2 + 1];
                    int erased = dp[idx2];
                    tmp[idx2] =  1 + min(replaced , min(inserted , erased));
                }
            }
            dp = tmp;
        }
        return dp[0];
    }
};
class Solution {
public:
    int numDistinctHelper(int idx1, int idx2 , string &s , string &t , vector<vector<int>> &dp){
        if(idx2 == t.size())return dp[idx1][idx2] = 1;
        if(idx1 == s.size())return dp[idx1][idx2] = 0;
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        if(s[idx1] == t[idx2]){
            int goingAhead = numDistinctHelper(idx1 + 1 , idx2 + 1 , s ,t , dp) ;
            int checkingForAnotherOne = numDistinctHelper(idx1 + 1 , idx2 , s , t , dp);
            return dp[idx1][idx2] = (goingAhead + checkingForAnotherOne); 
        }
        return dp[idx1][idx2] = numDistinctHelper(idx1 + 1 , idx2 , s ,t , dp);
    }
    int numDistinct(string s, string t) {
        /*
        //(recursion + memoization)
        vector<vector<int>>dp(s.size() + 1 , vector<int>(t.size() + 1 , -1));
        int result = numDistinctHelper(0 , 0 , s , t , dp);
        for(const auto &a : dp){
            for(const auto &b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return result;
        */
        /*
        //tabulation
        // vector<vector<unsigned long long>>dp(s.size() + 1 , vector<unsigned long long>(t.size() + 1 , 0));
        // vector<unsigned long long>dp(t.size() + 1 , 0);
        // for(int i=0; i<=s.size() ; i++){
        //     dp[i][t.size()] = 1;
        // }
        for(int idx1=s.size()-1 ; idx1>=0 ; idx1--){
            for(int idx2=t.size()-1 ; idx2>=0 ; idx2--){
                if(s[idx1] == t[idx2]){
                    dp[idx1][idx2] = (dp[idx1 + 1][idx2 + 1] + dp[idx1 + 1][idx2]); 
                }else{
                    dp[idx1][idx2] = dp[idx1 + 1][idx2];
                }
            }
        }
        return dp[0][0];
        */
        vector<unsigned long long>dp(t.size() + 1 , 0) , tmp(t.size() + 1 , 0);
        for(int idx1=s.size()-1 ; idx1>=0 ; idx1--){
            dp[t.size()] = 1;
            for(int idx2=t.size()-1 ; idx2>=0 ; idx2--){
                if(s[idx1] == t[idx2]){
                    tmp[idx2] = (dp[idx2 + 1] + dp[idx2]); 
                }else{
                    tmp[idx2] = dp[idx2];
                }
            }
            dp = tmp;
        }
        return dp[0];
    }
};
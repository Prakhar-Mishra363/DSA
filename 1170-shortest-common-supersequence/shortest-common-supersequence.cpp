class Solution {
public:
    int shortCommSuperseqHelper(int len1 , int len2 , const string &str1 , const string &str2 , vector<vector<int>> &dp){
        if(len2 == str2.size()){
            return dp[len1][len2] =  (str1.substr(len1)).length();
        }
        if(len1 == str1.size()){
            return dp[len1][len2] = (str2.substr(len2)).length();
        }
        if(dp[len1][len2] != -1)return dp[len1][len2];
        if(str1[len1] == str2[len2]){
            return dp[len1][len2] = 1 + shortCommSuperseqHelper(len1 + 1 , len2 + 1 , str1 , str2 , dp);
        }
        int addInFirstStr =  shortCommSuperseqHelper(len1 , len2 + 1 , str1 , str2 , dp);
        int addInSecondStr = shortCommSuperseqHelper(len1 + 1 , len2 , str1 , str2 , dp);
        return dp[len1][len2] = 1 + min(addInFirstStr , addInSecondStr);
    }
    string getMeFingResult(int len1 ,int len2 , string &str1 , string &str2 , vector<vector<int>> &dp){
        if(len2 == str2.size())return str1.substr(len1);
        if(len1 == str1.size())return str2.substr(len2);
        if(str1[len1] == str2[len2]){
            return str1[len1] + getMeFingResult(len1 + 1 , len2 + 1, str1 , str2 , dp);
        }
        return (dp[len1][len2 + 1] < dp[len1 + 1][len2]) ? str2[len2] + getMeFingResult(len1 , len2 + 1 , str1 , str2 ,
        dp) : str1[len1] + getMeFingResult(len1 + 1 , len2 , str1 , str2 , dp);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size() + 1 , vector<int>(str2.size() + 1 , -1));
        // int result = shortCommSuperseqHelper(0 , 0, str1 , str2 , dp);
        for(int i=0 ; i<=str2.size() ; i++ ){
            dp[str1.size()][i] = str2.size()-i;
        }
        for(int i=0;i<=str1.size() ; i++){
            dp[i][str2.size()] = str1.size()-i;
        }
        // vector<string>dp(str2.size() + 1 , "") , temp(str2.size() + 1 , "");
        // for(int i=0;i<=str2.size();i++){
        //     dp[i] = str2.substr(i);
        // }
        // string result = "";
        for(int len1 = str1.size()-1 ; len1>=0 ; len1--){
            for(int len2 = str2.size()-1 ; len2>=0 ; len2--){
                if(str1[len1] == str2[len2]){
                    dp[len1][len2] = 1 + dp[len1 + 1][len2 + 1];
                }else{
                    int addInFirstStr =  dp[len1][len2 + 1];
                    int addInSecondStr = dp[len1 + 1][len2];
                    dp[len1][len2] = 1 + min(addInFirstStr , addInSecondStr);
                }
            }
        }
        return getMeFingResult(0,0,str1 , str2 , dp);
        // for(auto a : dp){
        //     for(auto b : a){
        //         cout<<b<<" ";
        //     }cout<<endl;
        // }
        // for(int len1 = str1.size()-1 ; len1>=0 ; len1--){
        //     temp[str2.size()] = str1.substr(len1);
        //     for(int len2 = str2.size()-1 ; len2>=0 ; len2--){
        //         if(str1[len1] == str2[len2]){
        //             temp[len2] = str1[len1] + dp[len2 + 1];
        //         }else{
        //             string addInFirstStr =  str2[len2] + temp[len2 + 1];
        //             string addInSecondStr = str1[len1] + dp[len2];
        //             temp[len2] = (addInFirstStr.size() < addInSecondStr.size()) ? addInFirstStr : addInSecondStr;
        //         }
        //     }
        //     dp = temp;
        // }

        // return "";
    }
};
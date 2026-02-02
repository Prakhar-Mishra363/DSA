class Solution {
public:
    int numDecodingsHelper(int idx , string s , vector<int> &dp){
        if(idx >= s.size())return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx] != -1)return dp[idx];
        int ways=0;
        for(int i=idx ; i<min(idx+2 , (int)s.size()) ;i++){
            int curr_res=27-stoi(s.substr(idx , i-idx+1));
            if(curr_res >=1 && curr_res <= 26){
                ways += numDecodingsHelper(i+1 , s , dp);
            }
        }
        return dp[idx]=ways;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return numDecodingsHelper(0 , s , dp);
    }
};
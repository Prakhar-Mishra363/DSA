class Solution {
public:
    bool isPalindrom(int start , int end ,const string &s){
        while(start < end){
            if(s[start] != s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    int minCutHelper(int currIdx , const string &s , vector<int> &dp){
        if(currIdx == s.size())return dp[currIdx] = 0;
        int minCost = INT_MAX;
        // string temp = "";
        if(dp[currIdx] != -1)return dp[currIdx];
        for(int j=currIdx ; j<s.size() ; j++){
            // temp += s[j];
            if(isPalindrom(currIdx , j , s)){
                int cost = 1 + minCutHelper(j+1 , s , dp);
                minCost = min(minCost , cost);
            }
        }
        return dp[currIdx] = minCost;
    }
    int minCut(string s) {
        /* (recursion + memoization)
        vector<int>dp(s.size() + 1 , -1);
        int result = minCutHelper(0 ,  s , dp) - 1;
        return result;
        */
        //Tabulation
        int n = s.size();
        vector<int>dp(n+1 , 0);
        for(int idx = n-1 ; idx>=0 ; idx--){
            int minCost = INT_MAX;
            for(int j = idx ; j<n ; j++){
                if(isPalindrom(idx , j , s)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[idx] = minCost;
        }
        return dp[0]-1;
    }
};
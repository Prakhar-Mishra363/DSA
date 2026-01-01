class Solution {
public:
    /* recursion + memoization
    int minimumTotalHelper(int currRow,int currCol, const vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(dp[currRow][currCol] != -1)return dp[currRow][currCol];
        if(currRow == arr.size()-1)return dp[currRow][currCol] = arr[currRow][currCol];;
        int aheadIdx =  minimumTotalHelper(currRow+1,currCol+1,arr,dp) + arr[currRow][currCol];
        int sameIdx = minimumTotalHelper(currRow+1,currCol,arr,dp) + arr[currRow][currCol];
        return dp[currRow][currCol] = min(sameIdx,aheadIdx);
    }
    */
    int minimumTotal(vector<vector<int>>& arr) {
        if(arr.size()==1)return arr[0][0];
        int m = arr.size()-1;
        vector<vector<int>>dp(m+1);
        for(int i=0;i<=m;i++){
            dp[i].resize(arr[i].size(),-1);
        }
        /* -> recursion + memoization
        int result = minimumTotalHelper(0,0,arr,dp);
        return result;
        */
        //tabulation
        for(int i=0;i<arr[m].size();i++){
            dp[m][i] = arr[m][i];
        }
        for(int currRow = m-1; currRow>= 0 ;currRow--){
            int currCol=arr[currRow].size()-1;
            for(; currCol>=0 ; currCol--){
                dp[currRow][currCol] = min(dp[currRow+1][currCol],dp[currRow+1][currCol+1]) + arr[currRow][currCol] ;
            }
        }
        for(auto a : dp){
            for(auto b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return dp[0][0];
    }
};
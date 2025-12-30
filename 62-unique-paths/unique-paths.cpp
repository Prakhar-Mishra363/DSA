class Solution {
public:
    //recursion + memoization
    int uniquePathsHelper(int row, int col,int lastRow,int lastCol,vector<vector<int>>&dp){
        //we reached the destination
        if(row == lastRow && col == lastCol)return 1;
        //we are at the last row so the only available option is going right
        if(row == lastRow) return dp[row][col] = uniquePathsHelper(row,col+1,lastRow,lastCol,dp);
        //we are at the last col so only available option is going down
        if(col == lastCol) return dp[row][col] = uniquePathsHelper(row+1,col,lastRow,lastCol,dp);
        if(dp[row][col] != -1)return dp[row][col];
        //going to the right
        int right = uniquePathsHelper(row,col+1,lastRow,lastCol,dp);
        //going down
        int down = uniquePathsHelper(row+1,col,lastRow,lastCol,dp);
        return dp[row][col] = (right + down);
    }
    int uniquePaths(int m, int n) {
        //memoization
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        //optimization after seeing pattern in the problem
        /*for(int i=0;i<n;i++){
            dp[m-1][i]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][n-1] = 1;
        }
        for(int row = m-2; row >= 0; row--){
            for(int col = n-2; col >= 0; col--){
                dp[row][col] = dp[row+1][col] + dp[row][col+1];
            }
        }
        return dp[0][0];*/
        //using recursion + memoization
        // int result = uniquePathsHelper(0,0,m-1,n-1,dp);

        vector<int>dp(n,0);
        for(int row=0;row<m;row++){
            vector<int>temp(n,0);
            for(int col=0;col<n;col++){
                if(row == 0 && col == 0){
                    temp[col]=1;
                }else{
                    temp[col] = col == 0 ? dp[col] : temp[col-1] + dp[col];
                }
            }
            dp = temp;
        }
        return dp[n-1];
        
        // return result;
    }
};
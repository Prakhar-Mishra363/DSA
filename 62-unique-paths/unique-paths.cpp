class Solution {
public:
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
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int result = uniquePathsHelper(0,0,m-1,n-1,dp);
        for(auto a : dp){
            for(auto b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return result;
    }
};
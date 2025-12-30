class Solution {
public:
    int uniquePathsHelper(int row, int col,int lastRow,int lastCol,vector<vector<int>>&dp){
        if(row == lastRow && col == lastCol)return 1;
        if(row == lastRow) return uniquePathsHelper(row,col+1,lastRow,lastCol,dp);
        if(col == lastCol) return uniquePathsHelper(row+1,col,lastRow,lastCol,dp);
        if(dp[row][col] != -1)return dp[row][col];
        int right = uniquePathsHelper(row,col+1,lastRow,lastCol,dp);
        int down = uniquePathsHelper(row+1,col,lastRow,lastCol,dp);
        return dp[row][col] = (right + down);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return uniquePathsHelper(0,0,m-1,n-1,dp);
    }
};
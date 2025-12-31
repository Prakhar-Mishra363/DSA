class Solution {
public:
    int minPathSumHelper(int currentRow,int currentCol,const vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(dp[currentRow][currentCol] != -1)return dp[currentRow][currentCol];
        if(currentRow == grid.size()-1 && currentCol == grid[0].size()-1)return dp[currentRow][currentCol] = grid[currentRow][currentCol];
        if(currentRow == grid.size()-1)return dp[currentRow][currentCol] = minPathSumHelper(currentRow,currentCol+1,grid,dp) + grid
        [currentRow][currentCol];
        if(currentCol == grid[0].size()-1)return dp[currentRow][currentCol] = minPathSumHelper(currentRow+1,currentCol,grid,dp) + grid
        [currentRow][currentCol];
        int rightMove = minPathSumHelper(currentRow,currentCol+1,grid,dp) + grid[currentRow][currentCol];
        int downMove = minPathSumHelper(currentRow+1, currentCol, grid,dp) + grid[currentRow][currentCol];
        return dp[currentRow][currentCol] = min(rightMove,downMove);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        // dp[m-1][n-1] = grid[m-1][n-1];

        for(int currRow = m-1; currRow>=0; currRow--){
            for(int currCol = n-1; currCol>=0; currCol--){
                if(currRow == grid.size()-1 && currCol == grid[0].size()-1)dp[currRow][currCol] = grid[currRow][currCol];
                else if(currRow+1 == m)dp[currRow][currCol] = grid[currRow][currCol] + dp[currRow][currCol+1];
                else if(currCol+1 == n)dp[currRow][currCol] = grid[currRow][currCol] + dp[currRow+1][currCol];
                else dp[currRow][currCol] = grid[currRow][currCol] + min(dp[currRow][currCol+1],dp[currRow+1][currCol]);
            }
        }
        return dp[0][0];
        // int result = minPathSumHelper(0,0,grid,dp);
        // for(auto a:dp){
        //     for(auto b:a){
        //         cout<<b<<" ";
        //     }cout<<endl;
        // }
        // return result;
    }
};
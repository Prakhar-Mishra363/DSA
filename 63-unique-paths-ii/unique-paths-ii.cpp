class Solution {
public:
    // int uniquePathsWithObstaclesHelper(int currentRow,int currentCol,int lastRow,int lastCol,const vector<vector<int>>& obstacleGrid, 
    //    vector<vector<int>> &dp){
    //     if(obstacleGrid[currentRow][currentCol] == 1){
    //         dp[currentRow][currentCol] = 0;
    //         return 0;
    //     }
    //     if(currentRow == lastRow && currentCol == lastCol  )return 1;
    //     if(currentRow == lastRow)return dp[currentRow][currentCol] = uniquePathsWithObstaclesHelper(currentRow, currentCol+1, lastRow, lastCol,
    //     obstacleGrid,dp);
    //     if(currentCol == lastCol)return dp[currentRow][currentCol] = uniquePathsWithObstaclesHelper(currentRow+1, currentCol, lastRow, lastCol,
    //     obstacleGrid,dp);
    //     int right = uniquePathsWithObstaclesHelper(currentRow, currentCol+1, lastRow, lastCol,obstacleGrid,dp);
    //     int down = uniquePathsWithObstaclesHelper(currentRow+1, currentCol, lastRow, lastCol,obstacleGrid,dp);
    //     return dp[currentRow][currentCol] = (right + down);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1)return 0;
        vector<vector<long long>>dp(m,vector<long long>(n,-1));
        dp[m-1][n-1] = 1;
        for(int col=n-2; col>=0 ; col--){
            dp[m-1][col] = obstacleGrid[m-1][col] ? 0 : dp[m-1][col+1];
        }
        for(int row=m-2; row >= 0 ; row--){
            dp[row][n-1] = obstacleGrid[row][n-1] ? 0 : dp[row+1][n-1];
        }
        // int result = uniquePathsWithObstaclesHelper(0,0,m-1,n-1,obstacleGrid,dp);
        for(int row = m-2; row >= 0;row--){
            for(int col = n-2; col >= 0 ; col--){
                dp[row][col] = obstacleGrid[row][col] == 1 ? 0 : dp[row+1][col] + dp[row][col+1];
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
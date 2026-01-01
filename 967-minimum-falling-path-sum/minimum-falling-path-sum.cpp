class Solution {
public:
    int minFallingPathSumHelper(int currRow, int currCol,const vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(currCol < 0 || currCol >= matrix.size())return 1e5;
        if(dp[currRow][currCol] != -1)return dp[currRow][currCol];
        if(currRow == static_cast<int>(matrix.size())-1)return dp[currRow][currCol] = matrix[currRow][currCol];
        long leftCol = minFallingPathSumHelper(currRow+1,currCol-1,matrix,dp) + matrix[currRow][currCol];
        long downBelow = minFallingPathSumHelper(currRow+1,currCol,matrix,dp) + matrix[currRow][currCol];
        long rightCol = minFallingPathSumHelper(currRow+1,currCol+1,matrix,dp) + matrix[currRow][currCol];
        return dp[currRow][currCol] = min(leftCol,min(downBelow,rightCol));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minFallingPath = INT_MAX;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),-1));
        /* -> recursion + memoization
        for(int col=0;col<matrix.size();col++){
            int tempResult = minFallingPathSumHelper(0,col,matrix,dp);
            minFallingPath = min(minFallingPath,tempResult);
        }
        return minFallingPath;
        */
        for(int i=0;i<matrix.size();i++){
            dp[matrix.size()-1][i] = matrix[matrix.size()-1][i];
        }
        // int result = INT_MAX;
        for(int currRow = matrix.size()-2; currRow>=0; currRow--){
            for(int currCol = 0; currCol < matrix.size(); currCol++){
                int leftDiaCell = (currCol == 0) ? 1e5 : dp[currRow+1][currCol-1] + matrix[currRow][currCol];
                int downBelowCell = dp[currRow+1][currCol] + matrix[currRow][currCol];
                int rightDiaCell = (currCol == matrix.size()-1) ? 1e5 : dp[currRow+1][currCol+1] + matrix[currRow][currCol];
                dp[currRow][currCol] = min(leftDiaCell,min(downBelowCell,rightDiaCell));
                // result = min(result,dp[currRow,currCol]);
            }
        }
        for(auto a:dp){
            for(auto b:a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};
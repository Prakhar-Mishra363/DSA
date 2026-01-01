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
        vector<int>dp(matrix.size()); 
        dp = matrix[matrix.size()-1];
        /* -> recursion + memoization
        for(int col=0;col<matrix.size();col++){
            int tempResult = minFallingPathSumHelper(0,col,matrix,dp);
            minFallingPath = min(minFallingPath,tempResult);
        }
        return minFallingPath;
        */
        for(int currRow = matrix.size()-2; currRow>=0; currRow--){
            vector<int>temp(matrix.size(),0);
            for(int currCol = 0; currCol < matrix.size(); currCol++){
                int leftDiaCell = (currCol == 0) ? 1e5 : dp[currCol-1];
                int downBelowCell = dp[currCol];
                int rightDiaCell = (currCol == matrix.size()-1) ? 1e5 : dp[currCol+1];
                temp[currCol] = min(leftDiaCell,min(downBelowCell,rightDiaCell)) + matrix[currRow][currCol];
            }
            dp = temp;
        }
        for(auto a:dp){
            cout<<a<<" ";
        }
        return *min_element(dp.begin(),dp.end());
    }
};
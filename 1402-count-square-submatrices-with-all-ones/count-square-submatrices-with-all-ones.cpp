class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int total_matrices=0;
        for(int col=0 ; col<matrix[0].size() ; col++){
            dp[0][col]=matrix[0][col];
        }
        for(int row=0 ; row<matrix.size() ; row++){
            dp[row][0] = matrix[row][0];
        }
        for(int row=1 ; row<matrix.size() ; row++){
            for(int col=1 ; col<matrix[row].size() ; col++){
                if(matrix[row][col]){
                    if(dp[row-1][col]>0 && dp[row-1][col-1]>0  && dp[row][col-1]>0){
                        dp[row][col] = min(dp[row-1][col] , min(dp[row-1][col-1],dp[row][col-1])) + 1;
                    }else{
                        dp[row][col]=1;
                    }
                }else{
                    dp[row][col]=0;
                }
            }
        }
        for(auto &a:dp){
            total_matrices += accumulate(a.begin(),a.end(),0);
        }
        return total_matrices;
    }
};
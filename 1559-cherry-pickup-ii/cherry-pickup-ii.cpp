class Solution {
public:
    int cherryPickupHelper(int row, int col1,int col2,const vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(col1 < 0 || col1 >= grid[row].size() || col2 < 0 || col2 >= grid[row].size())return -1e8;
        if(dp[row][col1][col2] != -1)return dp[row][col1][col2];
        if(row == grid.size()-1){
            if(col1 == col2)return dp[row][col1][col2] = grid[row][col1];
            else return dp[row][col1][col2] = (grid[row][col1] + grid[row][col2]);
        }
        int currentMax = INT_MIN;
        vector<int>colVari = {-1,0,1};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(col1 == col2){
                    currentMax = max(currentMax,grid[row][col2] + cherryPickupHelper(row+1,col1+colVari[i],
                    col2+colVari[j],grid,dp));
                }else{
                    currentMax = max(currentMax,grid[row][col2] + grid[row][col1] + cherryPickupHelper(row
                    +1,col1+colVari[i],col2+colVari[j],grid,dp));
                }
            }
        }
        return dp[row][col1][col2] = currentMax;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return cherryPickupHelper(0,0,grid[0].size()-1,grid,dp);
    }
};
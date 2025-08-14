class Solution {
public:
    pair<int,int> isValid(const vector<vector<int>>& grid,int row, int col,int move){
        int n=grid.size()-1;
        if(row-2>=0&&col+1<=n){
            if(grid[row-2][col+1]==move)return {row-2,col+1};
        }
        if(row-1>=0&&col+2<=n){
            if(grid[row-1][col+2]==move)return {row-1,col+2};
        }
        if(row+1<=n&&col+2<=n){
            if(grid[row+1][col+2]==move)return {row+1,col+2};
        }
        if(row+2<=n&&col+1<=n){
            if(grid[row+2][col+1]==move)return {row+2,col+1};
        }
        if(row+2<=n&&col-1>=0){
            if(grid[row+2][col-1]==move)return {row+2,col-1};
        }
        if(row+1<=n&&col-2>=0){
            if(grid[row+1][col-2]==move)return {row+1,col-2};
        }
        if(row-1>=0&&col-2>=0){
            if(grid[row-1][col-2]==move)return {row-1,col-2};
        }
        if(row-2>=0&&col-1>=0){
            if(grid[row-2][col-1]==move)return {row-2,col-1};
        }
        return{-1,-1};
        
    }
    bool helper(const vector<vector<int>>& grid,int row, int col,int move){
        if(move==grid.size()*grid.size()-1)return true;
        pair<int,int>p=(isValid(grid,row,col,move+1));
        if(p.first==-1&&p.second==-1){
            return false;
        }else{
            return helper(grid,p.first,p.second,move+1);
        }
        
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return false;
        return helper(grid,0,0,0);
    }
};
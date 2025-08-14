class Solution {
public:
    pair<int,int> isValid(const vector<vector<int>>& grid,int row, int col,int move){
        int n=grid.size()-1;
        int dx[]={-2,-1,1,2,2,1,-1,-2};
        int dy[]={1,2,2,1,-1,-2,-2,-1};
        for(int i=0;i<8;i++){
            int nx=row+dx[i];
            int ny=col+dy[i];
            if(((nx>=0&&nx<=n)&&(ny>=0&&ny<=n))&&grid[nx][ny]==move){
                return{nx,ny};
            }
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
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==2){
                    q.push({{row,col},minutes});
                }
            }
        }
        vector<int>rows={0,0,-1,1};
        vector<int>cols={1,-1,0,0};
        while(!q.empty()){
            bool isExe = false;
            int currSize = q.size();
            for(int i=0;i<currSize;i++){
                pair<int,int>dim = q.front().first;
                int currMin = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int currRow = dim.first+rows[i];
                    int currCol = dim.second+cols[i];
                    if(currRow >= 0 && currRow <m 
                    && currCol >= 0 && currCol <n 
                    && grid[currRow][currCol]==1){
                        grid[currRow][currCol]=2;
                        q.push({{currRow,currCol},currMin+1});
                        isExe = true;
                    }
                }
            }
            if(isExe)minutes++;

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minutes;
        
    }
};
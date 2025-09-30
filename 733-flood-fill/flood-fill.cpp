class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int row = image.size();
        int col = image[0].size();
        int comColor;
        if(image[sr][sc]!=color){
            q.push({sr,sc});
            comColor = image[sr][sc];
            image[sr][sc]=color;
        }
        while(!q.empty()){
            pair<int,int>currCell = q.front();
            q.pop();
            vector<int>currRow = {-1,1,0,0};
            vector<int>currCol = {0,0,1,-1};
            for(int i=0;i<4;i++){
                int viaRow = currCell.first+currRow[i];
                int viaCol = currCell.second+currCol[i];
                if(viaRow >= 0 && viaRow < row && viaCol >= 0 && viaCol < col && 
                image[viaRow][viaCol]==comColor){
                    image[viaRow][viaCol]=color;
                    q.push({viaRow,viaCol});
                }
            }
        }
        return image;
    }
};
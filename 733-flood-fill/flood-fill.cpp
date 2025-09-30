class Solution {
    void dfs(vector<vector<int>>& copy,int sr,int sc,int comColor,int color){
        copy[sr][sc] = color;
        vector<int>possRow = {-1,0,1,0};
        vector<int>possCol = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int viaRow = sr+possRow[i];
            int viaCol = sc+possCol[i];
            if(viaRow >= 0 && viaRow <copy.size() && viaCol >= 0 &&
            viaCol < copy[0].size() && copy[viaRow][viaCol]==comColor){
                dfs(copy,viaRow,viaCol,comColor,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>copy = image;
        int comColor = 0;
        if(image[sr][sc]!=color){
            comColor = image[sr][sc];
            dfs(copy,sr,sc,comColor,color);
        }return copy;
    }
};
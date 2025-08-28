class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>v;
        for(int i=1;i<n-1;i++){
            int size=n-i;
            int col=i,row=0;
            while(size){
                v.push_back(grid[row][col]);
                size--;
                col++;row++;
            }
            sort(v.begin(),v.end());
            size=n-i;
            col=i;
            row=0;
            int idx=0;
            while(size){
                grid[row++][col++]=v[idx++];
                size--;
            }
            v.clear();
        }
        for(int i=0;i<n-1;i++){
            int size=n-i;
            int row=i,col=0;
            while(size){
                v.push_back(grid[row++][col++]);
                size--;
            }
            sort(v.begin(),v.end(),greater<int>());
            // reverse(v.begin(),v.end());
            size=n-i;
            row=i;
            col=0;
            int idx=0;
            while(size){
                grid[row++][col++]=v[idx++];
                size--;
            }
            v.clear();
        }
        return grid;
    }
};
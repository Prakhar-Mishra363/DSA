#include<unordered_set>
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>m;
        int n=grid.size();
        int a,b;
        int actualSum=0,expectedSum=0;
        expectedSum=((n*n)*((n*n)+1))/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actualSum+=grid[i][j];
                if(m.find(grid[i][j])!=m.end()){
                    //m.[grid[i][j]]=true;
                    a=grid[i][j];
                }else{
                    m.insert(grid[i][j]);
                }
            }
        }
        
    return {a, expectedSum+a-actualSum};
    }
};
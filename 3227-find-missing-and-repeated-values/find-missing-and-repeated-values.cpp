#include<map>
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,bool>m;
        int n=grid.size();
        int a,b;
        int actualSum,expectedSum=0;
        actualSum=((n*n)*((n*n)+1))/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                expectedSum+=grid[i][j];
                if(m.find(grid[i][j])!=m.end()){
                    //m.[grid[i][j]]=true;
                    a=grid[i][j];
                }else{
                    m[grid[i][j]]=false;
                }
            }
        }
        
    return {a, actualSum-expectedSum+a};
    }
};
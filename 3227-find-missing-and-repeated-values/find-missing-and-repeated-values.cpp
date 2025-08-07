#include<map>
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,bool>m;
        int n=grid.size();
        int a;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m.find(grid[i][j])!=m.end()){
                    //m.[grid[i][j]]=true;
                    a=grid[i][j];
                }else{
                    m[grid[i][j]]=false;
                }
            }
        }
        int count=1;
        int b=0;
        for(auto val:m){
            if(count==val.first){
                count++;
            }else{
                b=count;
                break;
            }
        }
        if(b==0){
            return {a,count};
        }else{
            return {a,b};
        }
    return {-1,-1};
    }
};
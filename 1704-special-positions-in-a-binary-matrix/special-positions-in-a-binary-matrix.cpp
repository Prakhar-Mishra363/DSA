class Solution {
public:
    bool is_special(int row , int col , int total_ones , vector<vector<int>> &mat , vector<vector<bool>> &is_one){
        //for rows
        for(int curr_row=row+1 ; curr_row<mat.size() ; curr_row++){
            if(mat[curr_row][col]){
                is_one[curr_row][col]=true;
                total_ones+=1;
            }
        }
        //for cols
        for(int curr_col=col+1 ; curr_col<mat[0].size() ; curr_col++){
            if(mat[row][curr_col]){
                is_one[row][curr_col]=true;
                total_ones+=1;
            }
        }
        return total_ones==1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int total_rows=mat.size() , total_cols=mat[0].size();
        int row=0 , col=0;
        int total_special_pos=0;
        vector<vector<bool>>is_one(total_rows , vector<bool>(total_cols,false));
        for( ; row<total_rows ; row++){
            for( col=0; col<total_cols ; col++){
                if(mat[row][col]){
                    if(!is_one[row][col] && is_special(row , col , 1 , mat , is_one)){
                        total_special_pos += 1;
                    }else{
                        is_special(row , col , 1 , mat , is_one);
                    }
                    is_one[row][col]=true;
                }
            }
        }
        // for(auto a:is_one){
        //     for(auto b:a)cout<<b<<" ";
        //     cout<<endl;
        // }
        return total_special_pos;
    }
};
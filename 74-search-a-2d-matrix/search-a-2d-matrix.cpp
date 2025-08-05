class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(target<=matrix[i][matrix[i].size()-1]){
                for(int col=0;col<matrix[i].size();col++){
                    if(matrix[i][col]==target)return true;
                }
                return false;
            }
        }return false;
    }
};
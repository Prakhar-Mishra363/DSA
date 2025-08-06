class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size()-1,right=matrix[0].size()-1,left=0;
        // int totalEle=(bottom+1)*(right+1);
        // int count = 0;
        vector<int> ansMat;
        while((left<=right)&&(top<=bottom)){
            
                for(int i=top;i<=right;i++){
                    ansMat.push_back(matrix[top][i]);
                }
            
           
                for(int i=top+1;i<=bottom;i++){
                    ansMat.push_back(matrix[i][right]);
                }
            
                for(int i=right-1;i>=left;i--){
                    if(top==bottom){
                        break;
                    }
                    ansMat.push_back(matrix[bottom][i]);
                }
            
            
           
                for(int i=bottom-1;i>=top+1;i--){
                    if(right==left){
                        break;
                    }
                    ansMat.push_back(matrix[i][left]);
                }
                bottom--;
                top++;
                right--;
                left++;
            
        }
        
        return ansMat;
    }
};
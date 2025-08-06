class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size()-1,right=matrix[0].size()-1,left=0;
        int totalEle=(bottom+1)*(right+1);
        int count = 0;
        vector<int> ansMat;
        while((left<=right)&&(top<=bottom)){
            if(count!=totalEle){
                for(int i=top;i<=right;i++){
                    ansMat.push_back(matrix[top][i]);
                    count++;
                }
                top++;
            }else{
                break;
            }
            if(count!=totalEle){
                for(int i=top;i<=bottom;i++){
                    ansMat.push_back(matrix[i][right]);
                    count++;
                }
                right--;
            }else{
                break;
            }
            if(count!=totalEle){
                for(int i=right;i>=left;i--){
                    ansMat.push_back(matrix[bottom][i]);
                    count++;
                }
                bottom--;
            }else{
                break;
            }
            if(count!=totalEle){
                for(int i=bottom;i>=top;i--){
                    ansMat.push_back(matrix[i][left]);
                    count++;
                }
                left++;
            }else{
                break;
            }
        }
        
        return ansMat;
    }
};
class Solution {
public:
bool isSafe(vector<string>&board,int row, int col,int n){
    //checks for rows
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q')return false;
    }
    //checks for columns
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q')return false;
    }
    //checks for left diagonal
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q')return false;
    }
    //check for right diagonal
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q')return false;
    }
    return true;
}
void solu(vector<string>&board,vector<vector<string>>& ans,int row, int n){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j,n)){
            board[row][j]='Q';
            solu(board,ans,row+1,n);
            board[row][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        solu(board,ans,0,n);
    return ans;
    }
};
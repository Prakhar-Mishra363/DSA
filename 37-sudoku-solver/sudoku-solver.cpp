class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row, int col,char ch){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch)return false;
        }
        //checks for the column
        for(int i=0;i<9;i++){
            if(board[i][col]==ch)return false;
        }
        int i;
        int x=row/3,y=col/3;
        if(x==0){
            x=0;
        }else if(x==1){
            x=3;
        }else{
            x=6;
        }
        if(y==0){
            y=0;
        }else if(y==1){
            y=3;
        }else{
            y=6;
        }
        for(int i=x;i<(x+3);i++){
            for(int j=y;j<(y+3);j++){
                if(board[i][j]==ch)return false;
            }
        }
        return true;
    }
    bool sol(vector<vector<char>>& board,int row,int col){
        if(col==9)row++,col=0;
        if(row==9)return true;
        if(board[row][col]!='.'){
            return sol(board,row,col+1);
        }
        for(char i='1';i<='9';i++){
            if(isSafe(board,row,col,(i))&&board[row][col]=='.'){
                board[row][col]=(i);
                // i++;
                bool ans=sol(board,row,col+1);
                if(ans)return true;
                // i--;
                board[row][col]='.';
            }
            
        }return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool ans=sol(board,0,0);
    }
};
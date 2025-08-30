class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col,char value){
        //check for row and column
        for(int i=0;i<9;i++){
            if(i!=col&&board[row][i]==value)return false;
            if(i!=row&&board[i][col]==value)return false;
        }
        int i=(row/3)*3;
        int j=(col/3)*3;
        for(int currRow=i;currRow<(i+3);currRow++){
            for(int currCol=j;currCol<(j+3);currCol++){
                if((currRow!=row&&currCol!=col)&&board[currRow][currCol]==value)return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        if(row==board.size())return true;
        if(col==board[row].size()){
           return helper(board,row+1,0);
        }
        if(board[row][col]=='.'){
           return helper(board,row,col+1);
        }
        bool ans = isValid(board,row,col,board[row][col]);
        if(!ans)return ans;
        return helper(board,row,col+1);
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return helper(board,0,0);
    }
};
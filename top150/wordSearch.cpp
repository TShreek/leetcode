class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int index=0;
        int x = board.size(), y =board[0].size();
        for(int i = 0;i < x; i++){
            for(int j=0;j<y;j++){
                if(board[i][j] == word[0]){
                    char saved = board[i][j];
                    board[i][j] = '#';
                    bool found = dfs(board,word,index+1,i,j,x,y);
                    if(found) return true;
                    board[i][j] = saved;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word,
    int index, int row, int col, int x, int y){
        if(index == word.size()){
            return true;
        }

        if(row > 0 && board[row-1][col] == word[index]) {
            char saved = board[row-1][col];
            board[row-1][col] = '#';
            if(dfs(board,word,index+1,row-1,col,x,y)) return true;
            board[row-1][col] = saved;
        }
        if(row +1 < x && board[row+1][col] == word[index]) {
            char saved =board[row+1][col];
            board[row+1][col] = '#';
            if(dfs(board,word,index+1,row+1,col,x,y)) return true;
            board[row+1][col] = saved;
        }
        if(col+1 < y && board[row][col+1] == word[index]) {
            char saved = board[row][col+1];
            board[row][col+1] = '#';
            if(dfs(board,word,index+1,row,col+1,x,y)) return true;
            board[row][col+1] = saved;
        }
        if(col > 0 && board[row][col-1] == word[index]) {
            char saved =  board[row][col-1];
            board[row][col-1] = '#';
            if (dfs(board,word,index+1,row,col-1,x,y)) return true;
            board[row][col-1] = saved;
        }
        return false;
    }
};

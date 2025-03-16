class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dirs = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},{0,1},
            {1,-1},{1,0},{1,1}
        };
       int rows = board.size();
       int cols = board[0].size();

       for(int i=0; i< rows;i++){
        for(int j=0; j< cols; j++){
            int neighbours=0;
            for(auto& dir : dirs){
                int n1 = i + dir[0], n2 = j + dir[1];
                if(n1 >= 0 && n1 < rows && n2 >= 0 && n2 < cols && (board[n1][n2] == 1 || board[n1][n2] == 2 )){
                    neighbours++;
                }
            }
            if(board[i][j] == 1 && (neighbours < 2 || neighbours > 3)){
                board[i][j] =2;
            }
            if(board[i][j] == 0 && (neighbours == 3)){
                board[i][j]=3;
            }
        }
       } 
       for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(board[i][j] == 2){
                board[i][j] =0;
            }
            if(board[i][j] == 3){
                board[i][j] =1;
            }
        }
       }
    }
};

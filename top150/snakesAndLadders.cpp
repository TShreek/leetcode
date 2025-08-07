class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flatten(n*n+1,-1);
        bool leftToRight = true;
        int index = 1;
        for(int row = n-1 ;row>=0 ; row--){
            if(leftToRight){
                for(int col = 0;col < n ; col++){
                    flatten[index++] = board[row][col];
                }
            }
            else{
                for(int col = n-1; col >= 0;col--){
                    flatten[index++] = board[row][col];
                }
            }
            leftToRight = !leftToRight;
        }
        queue<pair<int,int>> q;
        vector<bool> visited(n*n+1,false) ;
        q.push({1,0});
        visited[1] = true;
        while(!q.empty()){

            auto [curr, moves] = q.front(); q.pop();

            if(curr == n*n) return moves;
            for(int i=1;i<=6;i++){
                int next = curr + i;
                if(next > n*n) continue;
                int dest = (flatten[next] == -1)? next : flatten[next];

                if(!visited[dest]){
                    visited[dest]= true;
                    q.push({dest,moves+1});
                }
            }
        }
        return -1;
    }
};

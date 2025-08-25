class Solution {
public:
    int totalNQueens(int n) {
        vector<char> col(n,0);
        vector<char> diag(2*n -1 ,0);
        vector<char> anti(2*n-1, 0);
        int count=0;
        dfs(0,n,col,diag,anti,count);
        return count;
    }

    void dfs(int r, int n, vector<char>& col, vector<char>& diag, vector<char>& anti, int& count){
        if(r == n){
            count++;
            return;
        }
        for(int c = 0; c < n; c++){
            int d = r - c + (n-1);
            int ad = r + c;
            if(col[c] || diag[d] || anti[ad]) continue;

            col[c] = diag[d] = anti[ad] = 1;
            dfs(r+1,n,col,diag,anti,count);
            col[c]=diag[d]=anti[ad] = 0;
        }
    }
};

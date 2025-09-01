/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid,0,0,n);
    }

    Node* build(vector<vector<int>>& grid, int row, int col, int n){
        if(isUniform(grid,row,col,n)){
            return new Node(grid[row][col] == 1,true);
        }
        int half = n/2;

        Node* tl = build(grid, row, col, half);
        Node* tr = build(grid, row, col+half, half);
        Node* bl = build(grid, row + half, col, half);
        Node* br = build(grid, row+half, col+half, half);

        return new Node(true,false, tl,tr,bl,br);
    }

    bool isUniform(vector<vector<int>>& grid,int row,int col,int size){
        int first = grid[row][col];
        for(int i = row;i < row + size ;i++){
            for(int j = col ; j < col + size;j++){
                if(grid[i][j] != first) return false;
            }
        }
        return true;
    }
};

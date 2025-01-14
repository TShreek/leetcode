class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Create an auxiliary matrix to track changes
        vector<vector<bool>> boolMatrix(m, vector<bool>(n, false));

        // Step 1: Mark cells in boolMatrix for rows and columns with a 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    // Mark the entire row and column in boolMatrix
                    for (int k = 0; k < n; ++k) boolMatrix[i][k] = true;
                    for (int k = 0; k < m; ++k) boolMatrix[k][j] = true;
                }
            }
        }

        // Step 2: Update the matrix based on boolMatrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (boolMatrix[i][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

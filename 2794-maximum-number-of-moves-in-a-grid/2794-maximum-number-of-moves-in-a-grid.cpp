class Solution {
public:
    int maxMoves(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if (dp[row][col] != -1) return dp[row][col];

        int max_moves = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        if (row - 1 >= 0 && col + 1 < cols && grid[row - 1][col + 1] > grid[row][col]) {
            max_moves = max(max_moves, 1 + maxMoves(row - 1, col + 1, grid, dp));
        }
        if (col + 1 < cols && grid[row][col + 1] > grid[row][col]) {
            max_moves = max(max_moves, 1 + maxMoves(row, col + 1, grid, dp));
        }
        if (row + 1 < rows && col + 1 < cols && grid[row + 1][col + 1] > grid[row][col]) {
            max_moves = max(max_moves, 1 + maxMoves(row + 1, col + 1, grid, dp));
        }

        return dp[row][col] = max_moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int rowsize = grid.size();
        int colsize = grid[0].size();
        vector<vector<int>> dp(rowsize, vector<int>(colsize, -1));
        int max_moves = 0;

        for (int i = 0; i < rowsize; i++) {
            max_moves = max(max_moves, maxMoves(i, 0, grid, dp));
        }
        return max_moves;
    }
};
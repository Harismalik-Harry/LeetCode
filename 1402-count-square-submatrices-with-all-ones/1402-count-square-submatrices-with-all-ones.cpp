class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int countsubmatrix = 0;
        
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] ==   1) {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                    countsubmatrix=countsubmatrix+dp[i][j];
                }
            }
        }
        
        return countsubmatrix;
    }
    
};
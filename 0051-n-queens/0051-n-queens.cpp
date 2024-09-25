class Solution {
public:
    bool issafe(int row, int col, vector<vector<char>>& queens, int size) {
        int x = row, y = col;
        
        while (y >= 0) {
            if (queens[x][y] == 'Q') {
                return false;
            }
            y--;
        }

        x = row, y = col;
        while (x >= 0 && y >= 0) {
            if (queens[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }

        x = row, y = col;
        while (x < size && y >= 0) {
            if (queens[x][y] == 'Q') {
                return false;
            }
            x++;
            y--;
        }

        return true;
    }

    void addsolution(vector<vector<char>>& queens, vector<vector<string>>& sol, int size) {
        vector<string> temp;
        for (int i = 0; i < size; i++) {
            string s;
            for (int j = 0; j < size; j++) {
                s.push_back(queens[i][j]);
            }
            temp.push_back(s);
        }
        sol.push_back(temp);
    }

    void solution(vector<vector<char>>& queens, vector<vector<string>>& sol, int col, int size) {
        if (col == size) {
            addsolution(queens, sol, size);
            return;
        }

        for (int row = 0; row < size; row++) {
            if (issafe(row, col, queens, size)) {
                queens[row][col] = 'Q';
                solution(queens, sol, col + 1, size);
                queens[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> queens(n, vector<char>(n, '.'));
        vector<vector<string>> sol;
        solution(queens, sol, 0, n);
        return sol;
    }
};

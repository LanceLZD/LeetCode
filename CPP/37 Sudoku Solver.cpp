class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i==8 && j==9)
            return 1;
        if (j==9) {
            i++;
            j = 0;
        }
        if (board[i][j]=='.') {
            for (int k=0;k<9;k++) {
                board[i][j] = '1' + k;
                if (check(board, i, j, board[i][j]) && solve(board, i, j+1))
                    return 1;
                board[i][j] = '.';
            }
        }
        else {
            if (solve(board, i, j+1))
                return 1;
        }
        return 0;
    }
    
    bool check(vector<vector<char>>& board, int i, int j, char tmp) {
        for (int k=0;k<9;k++) {
            if (k==i)
                continue;
            if (board[k][j]==tmp)
                return 0;
        }
        for (int k=0;k<9;k++) {
            if (k==j)
                continue;
            if (board[i][k]==tmp)
                return 0;
        }
        for (int p=i/3*3;p<i/3*3+3;p++) {
            for (int q=j/3*3;q<j/3*3+3;q++) {
                if (p==i && q==j)
                    continue;
                if (board[p][q]==tmp)
                    return 0;
            }
        }
        return 1;
    }
};
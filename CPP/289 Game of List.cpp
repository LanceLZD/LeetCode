class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m==0)
            return;
        int n = board[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                int k = live(board, i, j, m, n);
                if (board[i][j]==1) {
                    if (k==2 || k==3)
                        board[i][j] |= 2;
                }
                else {
                    if (k==3)
                        board[i][j] |= 2;
                }
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
    
    int live(vector<vector<int>>& board, int i, int j, int m, int n) {
        int tmp = 0;
        tmp += add(board, i-1, j-1, m, n);
        tmp += add(board, i-1, j, m, n);
        tmp += add(board, i-1, j+1, m, n);
        tmp += add(board, i, j-1, m, n);
        tmp += add(board, i, j+1, m, n);
        tmp += add(board, i+1, j-1, m, n);
        tmp += add(board, i+1, j, m, n);
        tmp += add(board, i+1, j+1, m, n);
        return tmp;
    }
    
    int add(vector<vector<int>>& board, int i, int j, int m, int n) {
        if (i>=0 && j>=0 && i<m && j<n && (board[i][j] & 1 == 1))
            return 1;
        return 0;
    }
};
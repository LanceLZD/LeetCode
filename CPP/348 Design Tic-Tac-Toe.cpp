class TicTacToe {
private:
    vector<int> rows1, cols1, diag1, rows2, cols2, diag2;
    int len;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        len = n;
        rows1.resize(n,0);
        cols1.resize(n,0);
        diag1.resize(2,0);
        rows2.resize(n,0);
        cols2.resize(n,0);
        diag2.resize(2,0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player==1) {
            if (++rows1[row]==len || ++cols1[col]==len)
                return 1;
            if (row==col)
                if (++diag1[0]==len)
                    return 1;
            if (row+col==len-1)
                if (++diag1[1]==len)
                    return 1;
        }
        else {
            if (++rows2[row]==len || ++cols2[col]==len)
                return 2;
            if (row==col)
                if (++diag2[0]==len)
                    return 2;
            if (row+col==len-1)
                if (++diag2[1]==len)
                    return 2;            
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
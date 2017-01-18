class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9,vector<bool>(9,0)), cols(9,vector<bool>(9,0)), buckets(9,vector<bool>(9,0));
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j]!='.') {
                    int k = board[i][j] - '1';
                    if (rows[i][k] || cols[j][k] || buckets[i/3*3+j/3][k])
                        return 0;
                    rows[i][k] = 1;
                    cols[j][k] = 1;
                    buckets[i/3*3+j/3][k] = 1;
                }
            }
        }
        return 1;
    }
};
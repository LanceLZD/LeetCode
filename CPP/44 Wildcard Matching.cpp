class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> res(m+1, vector<bool>(n+1,0));
        res[0][0] = 1;
        for (int j=1;j<=n;j++) {
            if (p[j-1]=='*') {
                res[0][j] = res[0][j-1];
                for (int i=1;i<=m;i++) {
                    res[i][j] = (res[i][j-1] || res[i-1][j-1] || res[i-1][j]);
                }
            }
            else {
                for (int i=1;i<=m;i++) {
                    if (p[j-1]=='?' || s[i-1]==p[j-1])
                        res[i][j] = res[i-1][j-1];
                }
            }
        }
        return res[m][n];
    }
};
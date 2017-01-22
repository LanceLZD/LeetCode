class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int> m;
        for (int i=0;i<stones.size();i++)
            m[stones[i]] = i;
        vector<vector<bool>> rec(n, vector<bool>(n, 0));
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        rec[0][0] = 1;
        while (!q.empty()) {
            int now = q.front().first;
            int from = q.front().second;
            int jump = stones[now] - stones[from];
            for (int i=jump+1;i>=jump-1 && i>0;i--) {
                int aim = stones[now] + i;
                if (aim == stones[n-1])
                    return 1;
                if (m.find(aim)!=m.end() && !rec[m[aim]][now]) {
                    q.push(make_pair(m[aim], now));
                    rec[m[aim]][now] = 1;
                }
            }
            q.pop();
        }
        return 0;
    }
};
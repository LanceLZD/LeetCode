class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int tmp = INT_MAX;
        for (auto val:prices) {
            tmp = min(tmp, val);
            res = max(res, val-tmp);
        }
        return res;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int tmp = INT_MAX;
        for (auto val:prices) {
            if (val>tmp)
                res += val - tmp;
            tmp = val;
        }
        return res;
    }
};
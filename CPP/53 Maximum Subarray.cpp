class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int tmp = 0;
        for (auto val:nums) {
            tmp = max(tmp, 0);
            tmp += val;
            res = max(res, tmp);
        }
        return res;
    }
};
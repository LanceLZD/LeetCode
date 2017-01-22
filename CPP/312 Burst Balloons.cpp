class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i=n-3;i>=0;i--) {
            for (int j=i+2;j<n;j++) {
                for (int k=i+1;k<j;k++) {
                    res[i][j] = max(res[i][j], nums[i]*nums[j]*nums[k]+res[i][k]+res[k][j]);
                }
            }
        }
        return res[0][n-1];
    }
};
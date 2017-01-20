class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(target+1,0);
        res[0] = 1;
        for (int i=1;i<=target;i++) {
            for (int j=0;j<n;j++) {
                if (i-nums[j]>=0)
                    res[i] += res[i-nums[j]];
            }
        }
        return res[target];
    }
};
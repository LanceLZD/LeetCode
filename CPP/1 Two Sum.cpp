class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> tmp;
        for (int i=0;i<nums.size();i++)
            tmp.push_back(make_pair(nums[i],i));
        sort(tmp.begin(),tmp.end());
        int i = 0;
        int j = nums.size()-1;
        vector<int> res;
        while (i<j) {
            if (tmp[i].first+tmp[j].first==target) {
                res.push_back(tmp[i].second);
                res.push_back(tmp[j].second);
                return res;
            }
            else if (tmp[i].first+tmp[j].first<target)
                i++;
            else
                j--;
        }
        return res;
    }
};
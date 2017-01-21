class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(vector<int>{}, target, 0, candidates);
        return res;
    }
    
    void helper(vector<int> tmp, int target, int index, vector<int>& candidates) {
        if (target<0)
            return;
        else if (target==0)
            res.push_back(tmp);
        else {
            for (int i=index;i<candidates.size();i++) {
                tmp.push_back(candidates[i]);
                helper(tmp, target-candidates[i], i, candidates);
                tmp.pop_back();
            }
        }
    }
};
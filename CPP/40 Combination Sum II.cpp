class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(vector<int>{}, target, 0, candidates);
        return res;
    }
    
    void helper(vector<int> tmp, int target, int index, vector<int>& candidates) {
        if (target<0)
            return;
        else if (target==0)
            res.push_back(tmp);
        else {
            if (index==candidates.size())
                return;
            for (int i=index;i<candidates.size();i++) {
                if (i>index && candidates[i]==candidates[i-1])
                    continue;
                tmp.push_back(candidates[i]);
                helper(tmp, target-candidates[i], i+1, candidates);
                tmp.pop_back();
            }
        }
    }
};
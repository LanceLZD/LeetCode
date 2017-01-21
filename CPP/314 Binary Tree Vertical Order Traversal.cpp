/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        map<int, vector<int>> tmp;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            tmp[q.front().second].push_back(q.front().first->val);
            if (q.front().first->left)
                q.push(make_pair(q.front().first->left,q.front().second-1));
            if (q.front().first->right)
                q.push(make_pair(q.front().first->right,q.front().second+1));
            q.pop();
        }
        for (auto val=tmp.begin();val!=tmp.end();val++) {
            res.push_back(val->second);
        }
        return res;
    }
};
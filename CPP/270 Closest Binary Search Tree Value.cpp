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
private:
    int res;
public:
    int closestValue(TreeNode* root, double target) {
        res = root->val;
        helper(root, target);
        return res;
    }
    
    void helper(TreeNode* root, double target) {
        if (!root)
            return;
        if (root->val==target)
            res = root->val;
        else if (root->val>target) {
            if (abs(res-target)>root->val-target)
                res = root->val;
            helper(root->left, target);
        }
        else {
            if (abs(res-target)>target-root->val)
                res = root->val;
            helper(root->right, target);
        }
    }
};
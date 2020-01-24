// 687. Longest Univalue Path
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
    int helper(TreeNode *root, int &res) {
        if(root==NULL) return 0;
        int l = helper(root->left, res);
        int r = helper(root->right, res);
        int ls = 0, rs = 0;
        if(root->left!= NULL && root->left->val==root->val) {
            ls = l + 1;
        }
        if(root->right!= NULL && root->right->val==root->val) {
            rs = r + 1;
        }
        res = max(res, ls+rs);
        return max(ls, rs);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;
        helper(root, res);
        return res;
    }
};

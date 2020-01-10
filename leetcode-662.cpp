// https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    unsigned long res = 0;
    map<unsigned long, unsigned long> mp;
    long widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return res;
    }
    void dfs(TreeNode* root, unsigned long d, unsigned long p) {
        if(root==NULL) return;
        if(mp.find(d)==mp.end()) {
            mp.insert(make_pair(d, p));
        }
        res = max(res, p-mp[d]+1);
        dfs(root->left, d+1, 2*p+1);
        dfs(root->right, d+1, 2*p+2);
    }
};

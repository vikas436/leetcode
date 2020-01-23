// 987. Vertical Order Traversal of a Binary Tree
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
    bool comp(pair<int, int>p1, pair<int, int>p2) {
        return p1.first<p2.first;
    }
    void helper(TreeNode *root , map<int, vector<pair<int, int>>> &mp, int level, int depth) {
        if(root==NULL) return;
        if(mp.find(level)==mp.end()) {
            vector<pair<int, int>>vec;
            vec.push_back(make_pair(depth, root->val));
            mp[level]=vec;
        }else {
            mp[level].push_back(make_pair(depth, root->val));
        }
        helper(root->left, mp, level-1, depth+1);
        helper(root->right, mp, level+1, depth+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        map<int, vector<pair<int, int>>> mp;
        helper(root, mp, 0, 0);
        vector<pair<int,int>>vec;
        for(auto it=mp.begin();it!=mp.end();it++) {
            vec = it->second;
            sort(vec.begin(),vec.end());
            vector<int> temp;
            for(int i=0;i<vec.size();i++) {
                temp.push_back(vec[i].second);
            }
            res.push_back(temp);
        }
        return res;
    }
};

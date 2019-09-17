// 863. All Nodes Distance K in Binary Tree
/*
BFS implementation over tree in O(N).
distance from given nodes to all others nodes with level distance
*/


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
    void rootToLeaf(TreeNode *root, vector<TreeNode *>&vec, TreeNode *target,bool &update) {
        if(root==NULL) return;
        if(update==true) vec.push_back(root);
        if(root==target) update=false;
        
        rootToLeaf(root->left,vec,target,update);
        rootToLeaf(root->right,vec,target,update);
        if(update==true) vec.pop_back();
    }
    void distance(TreeNode *root, map<int,vector<int>>&mp,int k,set<TreeNode*>&st) {
        if(root==NULL) return;
        if(st.find(root)==st.end())
            mp[k].push_back(root->val);
        else return;
        distance(root->left,mp,k+1,st);
        distance(root->right,mp,k+1,st);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*>vec;
        bool update=true;
        rootToLeaf(root,vec,target,update);
        
        set<TreeNode*> st;
        map<int,vector<int>>mp;
        for(int i=0;i<vec.size();i++) {
            distance(vec[vec.size()-1-i],mp,i,st);
            st.insert(vec[vec.size()-1-i]);
        }
        // for(auto it=mp.begin();it!=mp.end();it++) {
        //     vector<int>temp=it->second;  
        //     cout<<it->first<<"     -> ";
        //     for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
        //     cout<<endl;
        // }
        vector<int>res=mp[K];
        return res;
    }
};


// 116. Populating Next Right Pointers in Each Node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node *res = root,*pre=NULL;
        queue<Node*> que;
        que.push(root);
        que.push(NULL);
        while(true) {
            root = que.front();
            que.pop();
            if(pre!=NULL) {
                pre->next = root;
            }
            pre = root;
            if(root==NULL) {
                if(que.empty() || que.front()==NULL) break;
                que.push(NULL);
            } else {
                if(root->left!=NULL)
                    que.push(root->left);
                if(root->right!=NULL)
                    que.push(root->right);
            }
        }
        return res;
    }
};

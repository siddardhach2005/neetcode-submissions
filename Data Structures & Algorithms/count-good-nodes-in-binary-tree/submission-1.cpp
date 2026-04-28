/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int g(TreeNode* root,int m){
        if(root==NULL) return 0;
        int c=0;
        if(root->val>=m) c=1;
        m=max(m,root->val);
        c+=g(root->left,m);
        c+=g(root->right,m);
        return c;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return g(root,root->val);
    }
};

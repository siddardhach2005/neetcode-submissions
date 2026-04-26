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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> a;
        vector<int> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> l;
            for(int i=0;i<s;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left!=NULL) q.push(n->left);
                if(n->right!=NULL) q.push(n->right);
                l.push_back(n->val);
            }
            a.push_back(l);
        }
        for(int i=0;i<a.size();i++){
            res.push_back(a[i].back());
        }
        return res;
    }
};

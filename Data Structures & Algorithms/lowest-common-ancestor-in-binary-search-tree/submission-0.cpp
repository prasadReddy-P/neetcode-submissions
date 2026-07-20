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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val1,val2;
        if(p->val<=q->val){
            val1 = p->val;
            val2 = q->val;
        }
        else{
            val1 = q->val;
            val2 = p->val;
        }
        if((val1<=root->val && val2>=root->val)) return root;
        if(val1<root->val && val2<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(val1>root->val && val2>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
    }
};

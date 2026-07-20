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
    int res = 1;
    void help(TreeNode* node,int maxVal){
        if(node == NULL) return;
        if(node->val>=maxVal){
            res++;
            maxVal = node->val;
        }
        help(node->left,maxVal);
        help(node->right,maxVal);
    }
    int goodNodes(TreeNode* root) {
        help(root->left,root->val);
        help(root->right,root->val);

        return res;
    }
};

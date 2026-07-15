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
    int width = 0;
    int calWidth(TreeNode* node){
        if(node == NULL) return 0;
        int l = calWidth(node->left);
        int h = calWidth(node->right);
        width = max(l+h,width);
        return max(l,h)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calWidth(root);
        return width;
    }
};

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
    pair<int,int> height(TreeNode* node){
        if(node == NULL) return {0,0};
        pair<int,int>p1 = height(node->left);
        int lHeight = p1.first;
        pair<int,int>p2 = height(node->right);
        int rHeight = p2.first;
        int currWidht = lHeight+rHeight;
        currWidht = max(max(p1.second,p2.second),currWidht);
        return {max(lHeight,rHeight)+1,currWidht};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>res = height(root);
        return res.second;
    }
};

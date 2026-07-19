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
    bool isSameTree(TreeNode* node1,TreeNode* node2){
        if(node1 == NULL || node2 == NULL) return node1 == node2;
        return node1->val == node2->val && isSameTree(node1->left,node2->left)&&isSameTree(node1->right,node2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(isSameTree(node,subRoot)) return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }
};

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
    //vector<int> maxDepth;
    int maxDepth(TreeNode * node){
        if (!node) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));

        
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
         int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (abs(leftDepth - rightDepth) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);}
};
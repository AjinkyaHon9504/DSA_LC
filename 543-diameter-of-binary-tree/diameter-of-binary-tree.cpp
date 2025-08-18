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
    int diameter = 0;

    int depth(TreeNode* root) {
        if (!root) return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        // update global diameter (edges = nodes - 1)
        diameter = max(diameter, left + right);

        return 1 + max(left, right); // return height of subtree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};

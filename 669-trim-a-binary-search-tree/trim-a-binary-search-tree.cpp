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

    TreeNode* trimBST(TreeNode* root, int low, int high) {

        if (!root)
            return NULL;

        // Case 1: root too small
        if (root->val < low)
            return trimBST(root->right, low, high);

        // Case 2: root too large
        if (root->val > high)
            return trimBST(root->left, low, high);

        // Case 3: root valid
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
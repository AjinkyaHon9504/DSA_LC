class Solution {
public:
    bool valid(TreeNode* node, long minval, long maxval) {
        if (!node) return true; // Empty subtree is valid
        if (node->val <= minval || node->val >= maxval) { // violation of BST property
            return false;
        }
        return valid(node->left, minval, node->val) && 
               valid(node->right, node->val, maxval); 
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};

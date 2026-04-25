class Solution {
public:

    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {

        if (!root) return;

        // Step 1: Traverse left
        inorder(root->left);

        // Step 2: Check violation
        if (prev && prev->val > root->val) {

            // First violation
            if (!first)
                first = prev;

            // Second violation
            second = root;
        }

        // Step 3: Update prev
        prev = root;

        // Step 4: Traverse right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        // Step 5: Swap incorrect nodes
        swap(first->val, second->val);
    }
};
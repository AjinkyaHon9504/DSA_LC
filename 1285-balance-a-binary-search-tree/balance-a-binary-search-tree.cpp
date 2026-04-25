class Solution {
public:

    void inorder(TreeNode* root, vector<int> &arr) {
        if (!root) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* construct(int l, int r, vector<int>& arr) {

        if (l > r) return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = construct(l, mid - 1, arr);
        root->right = construct(mid + 1, r, arr);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> arr;

        inorder(root, arr);

        return construct(0, arr.size() - 1, arr);
    }
};
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

    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorderTraversal(root->left, result);   // left
        result.push_back(root->val);           // root
        inorderTraversal(root->right, result); // right
    }

    bool findTarget(TreeNode* root, int k) {

         vector<int> inorder;
        inorderTraversal(root, inorder);

        int l=0,r=inorder.size()-1;
        while(l<r){
            int sum = inorder[l]+inorder[r];
            if(sum==k) return true;
            else if (sum < k) l++;
            else r--;
        }
        return false;
    }

    
};
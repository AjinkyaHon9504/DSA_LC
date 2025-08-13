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
vector<int> result;
 
    int maxDepth(TreeNode* root) {
        //base case for size=1 depth =1
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
 
};
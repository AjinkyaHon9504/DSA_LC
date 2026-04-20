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
    struct info{
        bool isBst;
        int sum;
        int minval;
        int maxval;
    };

    int maxSum = 0;
    info solve(TreeNode* root){
        if(root == NULL){
            return {true,0,INT_MAX,INT_MIN};
        }

    info left = solve(root->left);
    info right = solve(root->right);

    info curr;

    if(left.isBst && right.isBst && root->val > left.maxval && right.minval > root->val){
        curr.isBst = true;
        curr.sum=left.sum+ right.sum+ root->val;
        curr.minval = min(root->val , left.minval);
        curr.maxval = max(root->val, right.maxval);
        maxSum = max(maxSum,curr.sum);
    }
    else{
        curr.isBst = false;
        curr.sum = 0;
        curr.minval = INT_MIN;
        curr.maxval= INT_MAX;
    }

    return curr;

    }


    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
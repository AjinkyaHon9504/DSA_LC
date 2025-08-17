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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;    //case 1 null
        if (!p || !q) return false;     //case 2 one is null other is not 
        if (p->val != q->val) return false;  //case 3 Values are different
        return isSameTree(p->left, q->left) &&   //other case traverse
           isSameTree(p->right, q->right);}
};
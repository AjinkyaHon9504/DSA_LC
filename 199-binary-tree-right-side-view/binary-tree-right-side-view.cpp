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
    void righttree(TreeNode *root,int depth){
       if (!root) return;
       if (depth == result.size()) result.push_back(root->val);
       righttree(root->right, depth + 1);
       righttree(root->left, depth + 1);  

    }
    vector<int> rightSideView(TreeNode* root) {
     
        righttree(root,0);
        return result;
    }
};
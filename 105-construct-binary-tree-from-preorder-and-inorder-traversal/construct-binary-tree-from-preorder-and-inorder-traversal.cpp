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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return NULL;
        }
        TreeNode * node = new TreeNode(preorder[0]);
        int index=0;
        while(inorder[index]!=preorder[0]){
            index++;
        }
        vector<int>leftinor(inorder.begin(),inorder.begin()+index);
        vector<int>leftpreor(preorder.begin()+1,preorder.begin()+1+index);

        vector<int>rightinor(inorder.begin()+index+1,inorder.end());
        vector<int>rightpreor(preorder.begin()+index+1,preorder.end());

        node->right=buildTree(rightpreor,rightinor);
        node->left=buildTree(leftpreor,leftinor);
        return node;
    }
};
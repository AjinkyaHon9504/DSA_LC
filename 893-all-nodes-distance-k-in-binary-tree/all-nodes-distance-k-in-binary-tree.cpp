/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);

            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // to store parents
        markparent(root, parent);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int dist = 0;
          while (!q.empty()) {
            int size = q.size();
            if (dist == k) break;
            dist++;
            for(int i=0;i<size;i++){
                 TreeNode* node = q.front(); q.pop();
                 if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                 
                 }
                 if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                 }
                  if (parent.count(node) && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }

                 
            }


    }
     vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;}
};
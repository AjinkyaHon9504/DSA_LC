#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            maxWidth = max(maxWidth, end - start + 1);

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front(); q.pop();
                idx -= start; // normalization to prevent overflow
                if (node->left) q.push({node->left, 2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }
        }

        return (int)maxWidth;
    }
};


class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // Step 1: Build the original tree
        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        // Step 2: Find each node's new parent
        vector<int> newParent(n, -1);

        // Nearest ancestor for each character
        vector<int> last(26, -1);

        // Previous last value, used to restore DFS state
        vector<int> prev(n, -1);

        // Iterative DFS: {node, entering or exiting}
        stack<pair<int, bool>> st;
        st.push({0, true});

        while (!st.empty()) {
            auto [u, entering] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (entering) {
                // Save previous ancestor with this character
                prev[u] = last[c];

                // Determine new parent using ORIGINAL tree
                if (last[c] != -1) {
                    newParent[u] = last[c];
                } else {
                    newParent[u] = parent[u];
                }

                // Current node becomes nearest matching ancestor
                last[c] = u;

                // Exit event must happen after all children
                st.push({u, false});

                for (int v : children[u]) {
                    st.push({v, true});
                }
            } 
            else {
                // Restore state when leaving this subtree
                last[c] = prev[u];
            }
        }

        // Step 3: Build the modified tree
        vector<vector<int>> newChildren(n);

        for (int i = 1; i < n; i++) {
            newChildren[newParent[i]].push_back(i);
        }

        // Step 4: Get traversal order of modified tree
        vector<int> order;
        stack<int> stk;
        stk.push(0);

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();

            order.push_back(u);

            for (int v : newChildren[u]) {
                stk.push(v);
            }
        }

        // Step 5: Calculate subtree sizes bottom-up
        vector<int> ans(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (newParent[u] != -1) {
                ans[newParent[u]] += ans[u];
            }
        }

        return ans;
    }
};

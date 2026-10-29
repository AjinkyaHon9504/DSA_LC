
class Solution {
    using ll = long long;

    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout;
    vector<int> pref;
    vector<int> bit;
    int LOG, timer;

    int charMask(char c) {
        return 1 << (c - 'a');
    }

    void add(int idx, int val, int n) {
        for (int i = idx; i <= n + 1; i += i & -i) {
            bit[i] ^= val;
        }
    }

    int query(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            res ^= bit[i];
        }
        return res;
    }

    int getPrefix(int u) {
        return pref[u] ^ query(tin[u]);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k)) {
                u = up[k][u];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        pref.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        // Iterative DFS: avoids recursion stack overflow.
        // State 0 = entering a node, state 1 = exiting it.
        vector<tuple<int, int, int>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = ++timer;
                up[0][u] = p;
                pref[u] = (u == 0 ? 0 : pref[p])
                          ^ charMask(s[u]);

                st.push_back({u, p, 1});

                for (int i = (int)adj[u].size() - 1;
                     i >= 0; i--) {
                    int v = adj[u][i];
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        // Binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = charMask(s[u]) ^ charMask(c);

                // Update every root path in u's subtree.
                add(tin[u], delta, n);
                add(tout[u] + 1, delta, n);

                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int mask = getPrefix(u)
                         ^ getPrefix(v)
                         ^ charMask(s[w]);

                // At most one character may have odd frequency.
                ans.push_back(
                    mask == 0 || (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};

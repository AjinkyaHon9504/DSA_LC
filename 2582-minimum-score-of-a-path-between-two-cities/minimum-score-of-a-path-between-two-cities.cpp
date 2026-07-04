class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<bool> vis;
    int ans = INT_MAX;

    void dfs(int node) {
        vis[node] = true;

        for (auto &[next, wt] : adj[node]) {
            ans = min(ans, wt);

            if (!vis[next])
                dfs(next);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        vis.resize(n + 1, false);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(1);

        return ans;
    }
};
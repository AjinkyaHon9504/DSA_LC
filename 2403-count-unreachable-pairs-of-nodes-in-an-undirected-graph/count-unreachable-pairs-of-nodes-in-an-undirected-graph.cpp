class Solution {
public:
    void dfs(int u,
             unordered_map<int, vector<int>>& adj,
             vector<bool>& visited,
             int &size) {

        visited[u] = true;
        size++;

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, size);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        long long remnode = n;
        long long result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int Size = 0;
                dfs(i, adj, visited, Size);

                result += 1LL * Size * (remnode - Size);
                remnode -= Size;
            }
        }

        return result;
    }
};
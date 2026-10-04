class Solution {
public:

    bool dfs(vector<vector<int>>& graph,
             vector<int>& color,
             int curr,
             int currcolor) {

        color[curr] = currcolor;

        for (int v : graph[curr]) {

            // Same color → not bipartite
            if (color[v] == color[curr]) {
                return false;
            }

            // Uncolored → give opposite color
            if (color[v] == -1) {

                if (!dfs(graph, color, v, 1 - currcolor)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {

            // New connected component
            if (color[i] == -1) {

                if (!dfs(graph, color, i, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};
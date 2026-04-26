class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool dfs(int r, int c,
             int pr, int pc,
             vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < 4; i++) {

            int nr = r + dx[i];
            int nc = c + dy[i];

            // Boundary check
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            // Same character check
            if (grid[nr][nc] != grid[r][c])
                continue;

            // If not visited → DFS
            if (!visited[nr][nc]) {

                if (dfs(nr, nc, r, c, grid, visited))
                    return true;
            }

            // If visited AND not parent → cycle
            else if (nr != pr || nc != pc) {

                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m,
                                     vector<bool>(n, false));

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {

                    if (dfs(i, j, -1, -1,
                            grid, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
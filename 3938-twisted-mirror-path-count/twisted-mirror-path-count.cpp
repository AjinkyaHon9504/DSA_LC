
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dpR(m, vector<long long>(n, 0));
        vector<vector<long long>> dpD(m, vector<long long>(n, 0));

        // Start at (0, 0)
        dpR[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long R = dpR[i][j];
                long long D = dpD[i][j];

                if (grid[i][j] == 0) {

                    long long ways = (R + D) % MOD;

                    // Move right
                    if (j + 1 < n) {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + ways) % MOD;
                    }

                    // Move down
                    if (i + 1 < m) {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + ways) % MOD;
                    }

                } else {

                    // Mirror: right -> down
                    if (i + 1 < m) {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + R) % MOD;
                    }

                    // Mirror: down -> right
                    if (j + 1 < n) {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + D) % MOD;
                    }
                }
            }
        }

        return (dpR[m - 1][n - 1] +
                dpD[m - 1][n - 1]) % MOD;
    }
};

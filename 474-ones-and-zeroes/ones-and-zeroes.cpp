class Solution {
public:

    int solve(int i, int m, int n,
              vector<int>& ones,
              vector<int>& zeros,
              vector<vector<vector<int>>>& dp) {

        if (m < 0 || n < 0) {
            return -1e9;
        }

        if (i == ones.size()) {
            return 0;
        }

        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        // Pick current string
        int pick = 1 + solve(
            i + 1,
            m - zeros[i],
            n - ones[i],
            ones,
            zeros,
            dp
        );

        // Skip current string
        int skip = solve(
            i + 1,
            m,
            n,
            ones,
            zeros,
            dp
        );

        return dp[i][m][n] = max(pick, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<int> ones;
        vector<int> zeros;

        for (string s : strs) {

            int count = 0;

            for (char c : s) {
                if (c == '1') {
                    count++;
                }
            }

            ones.push_back(count);
            zeros.push_back(s.size() - count);
        }

        vector<vector<vector<int>>> dp(
            strs.size(),
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, -1)
            )
        );

        return solve(0, m, n, ones, zeros, dp);
    }
};
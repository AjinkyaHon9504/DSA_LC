class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        int k = 2;

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(k+1, LLONG_MIN))
        );

        // ✅ Correct initialization
        for(int a = 0; a <= k; a++) {
            if(coins[0][0] < 0 && a > 0)
                dp[0][0][a] = 0; // skip
            else
                dp[0][0][a] = coins[0][0];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;

                for(int a = 0; a <= k; a++) {

                    long long val = coins[i][j];

                    // from top
                    if(i > 0 && dp[i-1][j][a] != LLONG_MIN) {
                        dp[i][j][a] = max(dp[i][j][a],
                                          dp[i-1][j][a] + val);
                    }

                    // skip negative
                    if(val < 0 && a > 0) {
                        if(i > 0 && dp[i-1][j][a-1] != LLONG_MIN)
                            dp[i][j][a] = max(dp[i][j][a],
                                              dp[i-1][j][a-1]);

                        if(j > 0 && dp[i][j-1][a-1] != LLONG_MIN)
                            dp[i][j][a] = max(dp[i][j][a],
                                              dp[i][j-1][a-1]);
                    }

                    // from left
                    if(j > 0 && dp[i][j-1][a] != LLONG_MIN) {
                        dp[i][j][a] = max(dp[i][j][a],
                                          dp[i][j-1][a] + val);
                    }
                }
            }
        }

        long long ans = LLONG_MIN;
        for(int a = 0; a <= k; a++) {
            ans = max(ans, dp[n-1][m-1][a]);
        }

        return ans;
    }
};
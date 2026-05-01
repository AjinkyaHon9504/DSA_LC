class Solution {
public:
    int m, n;

    int getval(int x){
        if(x == 0) return 0;
        return 1;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k+1, INT_MIN))
        );

        // Base case: destination
        for(int cost = 0; cost <= k; cost++){
            int newcost = cost + getval(grid[m-1][n-1]);

            if(newcost <= k)
                dp[m-1][n-1][cost] = grid[m-1][n-1];
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){

                if(i == m-1 && j == n-1) continue;

                for(int cost = 0; cost <= k; cost++){

                    int newcost = cost + getval(grid[i][j]);

                    if(newcost > k) continue;

                    int right = (j+1 < n) ? dp[i][j+1][newcost] : INT_MIN;
                    int down  = (i+1 < m) ? dp[i+1][j][newcost] : INT_MIN;

                    if(right == INT_MIN && down == INT_MIN)
                        continue;

                    dp[i][j][cost] = max(right, down) + grid[i][j];
                }
            }
        }

        return dp[0][0][0] == INT_MIN ? -1 : dp[0][0][0];
    }
};
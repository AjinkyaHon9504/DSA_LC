class Solution {
public:
    int m, n;

    int getval(int x){
        if(x == 0) return 0;
        if(x == 1 || x == 2) return 1;
        return 0;
    }

    int solve(int i, int j, int cost, vector<vector<int>>& grid, int k,
              vector<vector<vector<int>>>& dp) {

        if(i >= m || j >= n) return INT_MIN;

        int newcost = cost + getval(grid[i][j]);

        if(newcost > k) return INT_MIN;

        if(i == m-1 && j == n-1)
            return grid[i][j];

        if(dp[i][j][newcost] != -1)
            return dp[i][j][newcost];

        int right = solve(i, j+1, newcost, grid, k, dp);
        int down = solve(i+1, j, newcost, grid, k, dp);

        if(right == INT_MIN && down == INT_MIN)
            return dp[i][j][newcost] = INT_MIN;

        return dp[i][j][newcost] = max(right, down) + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k+1, -1))
        );

        int result = solve(0, 0, 0, grid, k, dp);

        return result == INT_MIN ? -1 : result;
    }
};
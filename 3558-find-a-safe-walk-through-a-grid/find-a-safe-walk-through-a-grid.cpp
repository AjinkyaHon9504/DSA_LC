class Solution {
public:
    int m,n;
    vector<vector<int>>bestHealth;
    bool dfs(int i , int j ,vector<vector<int>>& grid, int health ){
        n = grid.size();
        m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m)return false;


        if(grid[i][j]==1){
            health--;
        }
        if(health<=0){
            return false;
        }
        if(i==n-1 && j==m-1){
            return true;
        }
        if(health<=bestHealth[i][j]){
            return false;
        }
        bestHealth[i][j]=health;

        // Right
        if (dfs(i, j + 1, grid, health))
        return true;

        // Left
        if (dfs(i, j - 1, grid,health))
        return true;

        // Down
       if (dfs(i + 1, j, grid,health))
        return true;

        // Up
        if (dfs(i - 1, j, grid,health))
        return true;

        return false;

    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        bestHealth.assign(n,vector<int>(m,-1));
        return dfs(0,0,grid,health);


    }
};
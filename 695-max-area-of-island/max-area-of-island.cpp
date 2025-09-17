class Solution {
public:

     int dfs(vector<vector<int>> &grid,int i,int j){
        int n= grid.size();
        int m=grid[0].size();

        //boundary check

          if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1)
        return 0;

        grid[i][j]=0;
        int area = 1;
        area += dfs(grid, i + 1, j);
        area += dfs(grid, i - 1, j);
        area += dfs(grid, i, j + 1);
        area += dfs(grid, i, j - 1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int maxArea=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area = dfs(grid,i,j);
                     maxArea = max(maxArea,area);
                }
            }


}
    return maxArea;
    }
};




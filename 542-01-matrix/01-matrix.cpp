class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n = mat[0].size();

        vector<vector<int>>dist (m,vector<int>(n,INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dirs = {0,1,0,-1,0};


        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr = r + dirs[k];
                int nc=c+ dirs[k+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
         return dist;
    }
};
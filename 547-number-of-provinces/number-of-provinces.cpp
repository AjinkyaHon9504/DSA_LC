class Solution {
public:

    void dfs(vector<vector<int>>& isConnected,vector<bool>&visited,int u){
        visited[u]=true;
        for(int v=0;v<isConnected.size();v++){
            if(isConnected[u][v]==1 && !visited[v]){
                dfs(isConnected,visited,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                dfs(isConnected,visited,i);
            }
        }
        return provinces;
    }
};
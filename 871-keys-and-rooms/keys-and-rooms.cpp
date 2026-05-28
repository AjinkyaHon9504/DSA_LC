class Solution {
public:

    void dfs(vector<vector<int>>&rooms,int source,vector<bool>&visited){
        visited[source]= true;
        for(int &it : rooms[source]){    // 0 ke lie it  = 1 and 3 
            if(!visited[it]){
                dfs(rooms,it,visited);
            }
        }
        }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        dfs(rooms,0,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
        
    }
};
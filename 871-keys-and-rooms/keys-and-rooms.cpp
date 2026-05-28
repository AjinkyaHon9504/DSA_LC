class Solution {
public:

    bool dfs(vector<vector<int>>&rooms,int source,vector<bool>&visited){
        visited[source]= true;
        for(int &it : rooms[source]){    // 0 ke lie it  = 1 and 3 
            if(!visited[it]){
                dfs(rooms,it,visited);
            }
        }
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        
        return dfs(rooms,0,visited);
    }
};
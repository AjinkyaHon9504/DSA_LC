class Solution {
public:

    bool check(unordered_map<int,vector<int>>&map,int source,int destination,vector<bool>&visited){
        if(source==destination){
            return true;
        }
        if(visited[source]==true){
            return false;
        }
        visited[source] = true;

        for(auto &it : map[source]){
            if(check(map,it,destination,visited)==true){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> map;

        for(auto &it : edges){
            map[it[0]].push_back(it[1]);
            map[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n, false);
        return check(map,source,destination,visited);
    }
};
class Solution {
public:
    bool iscycledfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<bool>&inrec,vector<int>&result,int u){
        visited[u]=true;
        inrec[u]=true;
        for(int &v:adj[u]){
            if(!visited[v] && iscycledfs(adj,visited,inrec,result,v)){
                return true;
            }
            else if(inrec[v]==true){
                return true;
            }
        }
        inrec[u]=false;
        result.push_back(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<bool>visited(numCourses,false);
        vector<bool>inrec(numCourses,false);
        vector<int>result;
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && iscycledfs(adj,visited,inrec,result,i)){
                return {};
            }
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
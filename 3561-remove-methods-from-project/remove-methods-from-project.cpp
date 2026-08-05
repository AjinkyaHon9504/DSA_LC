class Solution {
public:

    void dfs(int &k,vector<vector<int>>&adj,vector<bool>& sus){
        sus[k]=true;
        for(int v:adj[k]){
            if(!sus[v]){
                dfs(v,adj,sus);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        
        for(auto &e : invocations){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            
        }
        vector<bool>sus(n,false);
        dfs(k,adj,sus);

        for(auto &e:invocations){
            int u=e[0];
            int v=e[1];
            

            if(!sus[u] && sus[v]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    

                    ans.push_back(i);
                    
                }
                return ans;
            }

            }
            vector<int>ans;


            for(int i=0;i<n;i++){
                if(!sus[i]){
                    ans.push_back(i);
                }
                        

            }
            return ans;}
        
    
};
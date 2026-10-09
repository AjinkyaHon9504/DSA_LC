class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n);
        size.assign(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v){
            return;
        }
        if(size[u]<size[v]){
            swap(u,v);
        }
        parent[v]=u;
        size[u]+=size[v];
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DSU dsu(n);
        for(auto &edge : connections){
            dsu.unite(edge[0],edge[1]);

        }   
        int components = 0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i){
                components++;
            }
        }     
        return components -1;
    }
};
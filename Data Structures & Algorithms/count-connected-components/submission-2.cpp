class dsu{
    vector<int> rank,parent;
public:
    dsu(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    //path compression
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    bool unionbyrank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v){
            return false;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
            return true;
        }

    }
};
class Solution {
public:
   
    int countComponents(int n, vector<vector<int>>& edges) {
        dsu ds(n);
        int res=n;
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            if(ds.unionbyrank(u,v)){
                res--;
            }
        }
        return res;
    }
};

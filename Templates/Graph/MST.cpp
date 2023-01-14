//input -> v=no of vertices and adj list
// if overflow happens replace int with long
// output-> sum of MST
// E-edges V-vertices



// prims algorithm
// time complexity-> O(n+mlogm)
// space complexity->O(V) for vis


int spanningTreePrims(int V, vector<vector<int> > adj[]){
        int sum=0;
        vector<int>vis(V,0);
        // min heap for min wt edge
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
        pq.push({0,0});

        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]){continue;}
            vis[node]=1;
            sum+=wt;
            for(auto u:adj[node]){
                int adjnode=u[0];
                int wtadj=u[1];
                if(!vis[adjnode]){
                    pq.push({wtadj,adjnode});
                }
                
            }
        }
        return sum;
    }


// disjoint set union by rank and union by size
class DisjointSet{
    
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }

    }

    int findUltimateParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);
    }


    void unionByRank(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v){
            return;
        }

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;

        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u); 
        int ulp_v = findUltimateParent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }

};

//check input IMP
// Time Complexity-> O(ElogE) or O(ElogV)
// Space complexity-> O(V+E)
int kruskalMst(int V,vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            int node=i;
            int adjnode=it[0];
            int wt=it[1];
            edges.push_back({wt,{adjnode,node}});
        }
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(V);
    int cost=0;
    for(auto it:edges){
        int u=it.second.first;
        int v=it.second.second;
        int wt=it.first;
        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
            cost+=wt;
            ds.unionByRank(u,v);
            // ds.unionBySize(u,v);
            //both can be used union by rank and union by size
        }
    }
    return cost;
    
}
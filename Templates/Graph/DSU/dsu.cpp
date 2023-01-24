// disjoint set union by rank
// this is for graph which contains n nodes form 0 to n
class DisjointSet{
    vector<int>rank,parent;
    int cnt;
    public:
    DisjointSet(int n){
        cnt=n;
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
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
        --cnt;
    }
    int maxSize(vector<int> &parent) {
        vector<int> count(list.size());
        int max = 0;
        for (int i = 0; i < list.size(); i++) {
            count[root(i)]++;
            max = max(max, count[root(i)]);
        }
        return max;
    }

};
// disjoint set union by size





//Advanced DSU






// this is for general purpose dsu union by size use this always it is simpler
class DSU {
public:
    unordered_map<int,int> parent,size;
    vector<int>numsV;
    int cnt;
    //CUSTOM VECTOR OF NUMS
    DSU(vector<int>&nums){
        cnt=nums.size();
        numsV=nums;
        for(auto i:nums){
            parent[i]=i;
            size[i]=1;
        }
        
    }
    // NODES FROM 0-N
    DSU(int n){
        cnt=n;
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }


    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }


    void UnionBySize(int u,int v){
        int parent_u=findParent(u);int parent_v=findParent(v);

        if(parent_u==parent_v) return;

        if(parent_u!=parent_v){
            if(size[parent_v]>size[parent_u]){
                swap(parent_v,parent_u);
            }
        
          parent[parent_v]=parent_u;
          size[parent_u]+=size[parent_v];
          --cnt;
        }
    }

    int maxSize() {

        int maxi=0;
        for(auto i:numsV){
            maxi=max(maxi,size[i]);
        }

        return maxi;    
        
    }

};
// cnt->number of components
// size-size of componenent in which nums[i] lies

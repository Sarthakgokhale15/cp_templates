
// not for negative edges graph
// Function to find the shortest distance of all the vertices from the source vertex S.
// here params is adjacency vector
// Only using  greedy gives incorrect answer

/*
Time Complexity: O(V^2).
Space Complexity: O(V^2).
REFER GFG/ CP HANDBOOK
*/
vector<int> dijkstra(int v, vector<vector<int> > adj[], int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(v, INT_MAX);
    // dist of source from source is 0
    dist[source] = 0;

    pq.push({0, source});
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int node = p.second;

        for (auto it : adj[node])
        {

            int n = it[0]; // this is node
            int d = it[1]; // this is its weight

            if (dist[n] > dist[node] + d)
            {

                // when we want to reach nth vertex from node(parent) and its dist from dist[parent]+its weight if we get min dist then push to priority_queue and store it in dist vector
                dist[n] = dist[node] + d;
                pq.push({dist[n], n});
            }
        }
    }

    return dist;
}


// input will be edge list 
// algorithm makes n-1 rounds
// if k rounds are required then store the dist array in temp array beacuse modyfying in place will affect ans
// megative edges can be identified using BF

// Time Complexity: O(V*E).
// Space Complexity: O(V).

vector<int>bellmanFord(int v,vector<vector<int>>edge,int source){
    vector<int>dist(v+1,INT_MAX);
    dist[source]=0;
    for(int i=1;i<=n-1;i++){
        for(auto e:edges){
            int a=e[0];
            int b=e[1];
            int w=e[2];
            dist[b]=min(dist[b],dist[a]+w);
        }
    }
    return dist;
}




// the algorithm can only be used when the graph is so small that a cubic time complexity is fast enough.
// distance[a][b] is the shortest distance between nodes a and b. 
// here params is adjacency matrix


// Time Complexity: O(V^3).
// Space Complexity: O(V^2).
vector<vector<int>>floydWarshalls(int v,vector<vector<int>>adjMatrix){
    /* Building distance array starts*/
    vector<vector<int>>dist(v+1,vector<int>(v+1,INT_MAX));
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else if(adj[i][j]){
                dist[i][j]=adj[i][j];
            }
            else{
                dist[i][j]=INT_MAX;
            }
        }
    }
    /* Building distance array ends*/


    /*Main algorithm starts*/
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                dist[i][j]=min(dist[i][j]+dist[i][k]+dist[k][j]);
            }
        }
    }
    /*Main algorithm ends*/

    return dist;

    
}
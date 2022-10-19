

// Function to find the shortest distance of all the vertices
// from the source vertex S.

// here parms is adjacency vector

// Only using  greedy gives incorrect answer
/*
STEP 1: Think greedy for every vertex
STEP 2:when we get min dist store it and push to priority_queue
STEP 3: return dist vector


Time Complexity: O(V^2).
Space Complexity: O(V^2).
REFER GFG/ CP HANDBOOK

*/
vector<int> dijkstra(int v, vector<vector<int> > adj[], int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(v, INT_MAX);
    // dist of source from sourse is 0
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
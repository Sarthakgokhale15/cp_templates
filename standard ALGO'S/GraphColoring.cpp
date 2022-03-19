/*
Approach:
if graph is not cyclic, then return true
if cycle is present, then if no. of nodes in cycle is odd theb return false else return true

STEP 1:  MAINTAIN A VISITED ARRAY (COLOR) -1  ->not coloured and 1/0 for red/blue and vice-versa
STEP 2:The idea is to color the starting node blue, all its neighbors red, all their neighbors blue, and so on.
 If at some point of the search we notice that two adjacent nodes have the same color, this means that the graph is not bipartite.

 Time Complexity: O(V + E)
 Space Complexity: O(V)

*/

bool dfs(int i, int par, vector<int> adj[], vector<int> &color)
{
    color[i] = 1 - par;

    for (auto it : adj[i])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, color[i], adj, color))
            {
                return false;
            }
        }
        else if (color[it] == color[i])
        {
            return false;
        }
    }
    return true;
}

bool bfs(int i, int par, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    color[i] = 1 - par;
    q.push(i);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);

    for (int i = 0; i < v; i++)
    {
        // if its not coloured
        if (color[i] == -1)
        {
            // here use bfs/dfs
            if (!bfs(i, 0, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}

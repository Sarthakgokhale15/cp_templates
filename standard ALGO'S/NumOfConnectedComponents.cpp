
/*
Approach :
step 1: USE DFS FOR MARKING ALL NODES THAT WE CAN VISIT WITH ONE Nodes
step 2: if node is node is not marked visited then mark it visited and its connected nodes ans++
step 3: can use bfs for it but getting wrong ans


TIME COMPLEXITY: O(V^2);
SPACE COMPLEXITY:O(V)
*/
void dfs(vector<vector<int> > &adj, vector<int> &vis, int i, int v)
{
    if (vis[i])
        return;
    vis[i] = 1;
    for (int nbr = 0; nbr < v; nbr++)
    {
        if (adj[i][nbr] && !vis[nbr])
        {

            dfs(adj, vis, nbr, v);
        }
    }
}

int numProvinces(vector<vector<int> > adj, int v)
{
    vector<int> vis(v, 0);
    int ans = 0;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(adj, vis, i, v);

            ans++;
        }
    }

    return ans;
}
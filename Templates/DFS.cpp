void dfs(vector<int> &ans, vector<int> adj[], map<int, bool> &visited, int src)
{

    if (visited[src])
        return;
    ans.push_back(src);
    visited[src] = 1;

    for (auto u : adj[src])
    {
        dfs(ans, adj, visited, u);
    }
}
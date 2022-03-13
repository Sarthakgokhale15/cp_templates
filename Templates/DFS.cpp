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

##############GENERAL DFS################ 


void dfs(vector<vector<int> > &grid, vector<vector<int> > &visited, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1 || grid[i][j] == 0)
    {
        return;
    }

    visited[i][j] = 1;
    dfs(grid, visited, i - 1, j, n, m);
    dfs(grid, visited, i + 1, j, n, m);
    dfs(grid, visited, i, j - 1, n, m);
    dfs(grid, visited, i, j + 1, n, m);
}
for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    id=i,jd=j;
                }
                if(grid[i][j]==1){
                  a=i,b=j;
                }
            }
        }
        dfs(grid,a,b,n,m);

##############GENERAL DFS################ 
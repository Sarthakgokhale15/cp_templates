/*



1-->>USING DFS
Step 1: nothing but in general dfs but use backtracking
step 2:after ending the stack calls before returning add node to vector
ste 3: reverse this vector to get final topo sort vector



2-->>USING BFS    --(KAHN'S ALGO)

Mandatory step FIND INDEGREE OF EACH NODE

we have to add those nodes first whose indegree is zero
step 1: add nodes to the queue whose indegree is zero
step 2: then travel to all its neighbors and decrese their indegree if indegree of any neighbour is ero then push it to the queue
step 3:after that add popped node to ans
step 4:return ans


*/
void dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ans);
        }
    }

    ans.push_back(i);
    // return;
}
vector<int> bfs(int v, vector<int> adj[], vector<int> &indegree)
{

    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (!indegree[it])
            {
                q.push(it);
            }
        }

        ans.push_back(node);
    }

    return ans;
}

vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> ans;

    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // for DFS beloe step
    //             for(int i=0;i<v;i++){
    //      if(!vis[i]){
    //          solve(i,adj,vis,ans);
    //      }
    //  }
    //  reverse(ans.begin(),ans.end());

    //  for bfs below step

    ans = bfs(v, adj, indegree);

    return ans;
}
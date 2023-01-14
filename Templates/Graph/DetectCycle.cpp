// in undirected graph

/*
1:USING DFS->
STEP1 :RECURSIVELY CHECK IF ANY NODE ALREADY VISITED THEN RETURN truE
STEP 2 : IF NODE IS  ALREADY VISITED AND IT IS NOT ITS PARENT THEN RETURN TRUE ->THIS IS DUE TO WE DONT KNOW THE DIRECTION  IN GRAPH SO WE ONLY KNOW  THE EDGE EXIST
STEP E : IF NOT RETURN FALSE


2>USING BFS
STTEP 1:IN THIS DFS STORE THE NODE AND ITS PARENT AS
STEP 2: IF NODE IS  ALREADY VISITED AND IT IS NOT ITS PARENT THEN RETURN TRUE ->THIS IS DUE TO WE DONT KNOW THE DIRECTION  IN GRAPH SO WE ONLY KNOW  THE EDGE EXIST

*/
bool dfs(int par, int i, vector<int> adj[], vector<int> &vis)

{

    vis[i] = 1;

    for (auto it : adj[i])

    {

        if (!vis[it])

        {

            if (dfs(i, it, adj, vis))

                return true;
        }

        else

        {

            if (it != par)

            {

                return true;
            }
        }
    }

    return false;
}

bool bfs(int v, int i, vector<int> adj[], vector<int> &vis)

{
    vis[i] = 1;
    queue<pair<int, int> > q;

    q.push({i, -1});

    // if neighbour is already visited then return true else return fasle

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }
            else if (it != parent)
            {
                return true;
            }
        }
    }

    return false;
}

// IN DIRECTED GRAPH:

// IMP -->if cycle is present then its topological sort is not possible
// IMP--> if any neighbour is present in rec ancestor stack that means cycle is present then return true

/*
1:USING DFS
Step 1: Create recursive stack and mark vis[i]=1 and rec_stack[i]=1
IMP->recusrive stack me uske saare ancestora store honge at any rec dfs call e.g 1->2->3->(4,5) 4->5  suppose re call made for 5 then in rec=1,2,3,4
step 2:if node is not visited then recurrsively call dfs
step3: if node is already visited then check if it is marked in recursive stack if it is marked that means it is connected to one of its ancestors to form a cycle

step 4: after function call ends again remove node from rec_stack




2:USING BFS
 that means if topological sort is possible then cycle is present in directed graph else not present
 otherwise same algo as topo sort
 if(ans.size()==v)return false;
else return true;


*/
bool dfs(int i, vector<int> &rec_stack, vector<int> adj[], vector<int> &vis)
{

    rec_stack[i] = 1;
    vis[i] = 1;
    for (auto u : adj[i])
    {
        if (!vis[u])
        {
            if (dfs(u, rec_stack, adj, vis))
                return true;
        }
        else if (rec_stack[u])
            return true;
    }
    rec_stack[i] = 0;
    return false;
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
bool isCyclic(int v, vector<int> adj[])
{
    vector<int> indegree(v, 0);
    vector<int> ans;
    // vector<int>vis(v,0);
    // vector<int>rec_stack(v,0);

    // for(int i=0;i<v;i++){
    //     if(!vis[i]){
    //         if(dfs(i,rec_stack,adj,vis)){
    //             return true;
    //         }
    //     }
    // }
    // return false;

    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    ans = bfs(v, adj, indegree);
    if (ans.size() == v)
        return false;
    return true;
}
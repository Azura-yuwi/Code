//CSES Additional Problems
//USACO Guide BFS-->how to use bfs to detect cycle; O(V(V+E))

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[2500];
int cyc[2500];

void bfs(int src, int& n)
{
    int dist[n];
    queue<int> q;
    cyc[src] = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        dist[i] = -1;
    }
    
    dist[src] = 0; q.push(src);

    while(!q.empty())
    {
        int at = q.front(); q.pop();

        for(int to : adj[at])
        {
            if(dist[to] == -1)
            {
                q.push(to);
                dist[to] = dist[at] + 1;
            }
            else if(dist[to] >= dist[at]) //b/c in bfs, if meet cycle, must meet at opposite of the src --> distances will be about equivaluent
            {
                cyc[src] = min(cyc[src], dist[to] + dist[at] + 1);
            }
        }
    }

    return;
}


int main()
{
    int n,m; cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    int ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        bfs(i, n);
        ans =  min(ans, cyc[i]);
    }

    if(ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
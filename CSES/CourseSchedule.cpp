//CSES Graph
//USACO Guide Topological Sort
//Topological Sort (BFS)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n,m;
    cin >> n >> m;

    int in[n];
    vector<int> adj[n];

    for(int i = 0; i < n; i++)
    {
        in[i] = 0;
    }

    vector<int> ans;

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        in[b-1]++;
    }

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int get = q.front();
        q.pop(); ans.pb(get);

        for(int to : adj[get])
        {
            in[to]--;

            if(in[to] == 0)
            {
                q.push(to);
            }
        }
    }

    if(ans.size() < n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for(int i : ans)
        {
            cout << (i+1) << " ";
        }
    }
}

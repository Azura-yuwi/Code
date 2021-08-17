//CSES Graph
//Shortest Path--Bellman Ford, "Negative" Cycles
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_tuple
#define pb push_back
#define f first 
#define s second

int main()
{
    int n,m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges; 

    ll dist[n];
    bool adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                adj[i][j] = true; //true if you can reach j from i
            }
            else
            {
                adj[i][j] = false;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        dist[i] = -(1e9)*2500 - 100;
    }

    dist[0] = 0;

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb(mp(a-1,b-1,w));

        for(int j = 0; j < n; j++)
        {
            adj[a-1][j] = adj[a-1][j]|adj[b-1][j];
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        cout << "ROUND " << i << endl;
        cout << endl;

        for(auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            cout << a << " " << b << " " << w << " " << dist[b] << endl;
            dist[b] = max(dist[b], dist[a] + w);
            cout << dist[b] << endl;
        }

        cout << endl;
    }

    ll copy[n];

    for(int i = 0; i < n; i++)
    {
        cout << i << " DIST " << dist[i] << endl;
        copy[i] = dist[i];
    }

    cout << endl;
    cout << "COPY" << endl;

    //for(int i = 1; i < n; i++)
    //{
        for(auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            copy[b] = max(copy[b], copy[a] + w);
        }

        for(int i = 0; i < n; i++)
        {
            cout << i << "  DIST " << copy[i] << " " << adj[0][i] << " " << adj[i][n-1] << endl;
            if(copy[i] > dist[i] && adj[0][i] && adj[i][n-1])
            {
                cout << -1;
                return 0;
            }
        }
    //}

    cout << dist[n-1];

 }
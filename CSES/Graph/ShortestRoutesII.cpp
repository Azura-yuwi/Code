//CSES Graph
//Shortest Path--Floyd Warshall
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

int main()
{
    int n,m,q;
    cin >> n >> m >> q;

    int adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a-1][b-1] = min(adj[a-1][b-1], w);
        adj[b-1][a-1] = min(adj[b-1][a-1], w);
    }


    ll dist[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                dist[i][j] = 0;
            }
            else if(adj[i][j] != INT_MAX)
            {
                dist[i][j] = adj[i][j];
            }
            else
            {
                dist[i][j] = LLONG_MAX/2;
            }
        }
    }

    
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j] ,dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if(dist[a-1][b-1] == LLONG_MAX/2)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[a-1][b-1] << endl;
        }
    }
}
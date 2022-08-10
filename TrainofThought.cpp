#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

//vector<int> adj[1000];

int main()
{
    int n,m; cin >> n >> m;
    ll adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 1e12 + 1;

            if(i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    unordered_map<string, int> indexes;
    int on = 0;

    for(int i = 0; i < m; i++)
    {
        string a,b; ll c; cin >> a >> b >> c;
        //cout << "read " << a << " " << b << " " << c << endl;
        if(indexes.find(a) == indexes.end())
        {
            indexes[a] = on; on++;
        }

        if(indexes.find(b) == indexes.end())
        {
            indexes[b] = on; on++;
        }
        
        adj[indexes[a]][indexes[b]] = min(adj[indexes[a]][indexes[b]], c);

    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }

/*
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }*/

    int q; cin >> q;

    for(int i = 0; i < q; i++)
    {
        string a,b; cin >> a >> b; ll v = adj[indexes[a]][indexes[b]];
        if(v == 1e12 + 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << v << endl;
        }
    }

}
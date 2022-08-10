#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int root[20];

int find(int a)
{
    if(root[a] < 0)
    {
        return a;
    }

    root[a] = find(root[a]);
    return root[a];
}

bool unite(int a, int b)
{
    a = find(a); b = find(b);

    if(a == b) return false;

    if(root[a] > root[b]) swap(a,b);

    root[a] += root[b];
    root[b] = a;
    return true;
}

int main()
{
    int n,k; cin >> n >> k;
    int adj[n][n];
    vector<pair<int, pair<int,int>>> edges;

    for(int i = 0; i < n; i++)
    {
        root[i] = -1;

        for(int j = 0; j < n; j++)
        {
            cin >> adj[i][j];

            if(i != j)
            {
                edges.pb(mp(adj[i][j], mp(i,j)));
            }
        }
    }

    sort(edges.begin(), edges.end());

    int groups = n;

    if(n == k)
    {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 0;

    for(int i = 0; i < edges.size(); i++)
    {
        int a,b,c; c = edges[i].f; tie(a,b) = edges[i].s;

        if(unite(a,b))
        {
            groups--;
            ans += c;

            if(groups == k)
            {
                break;
            }
        }
    }

    cout << ans << endl;

}
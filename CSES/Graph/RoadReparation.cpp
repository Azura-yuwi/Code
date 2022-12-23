//USACO Min Span Tree
//CSES Graph
//MST -- Krsuskal+DSU

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_tuple


struct DSU {
    vector<int> root;

    void init(int n) {root.assign(n, -1);} 

    int find(int src)
    {
        if(root[src] < 0) { return src;}

        root[src] = find(root[src]); //compress
        return root[src];
    }   

    bool unite(int a, int b) //united or not
    {
        a = find(a); b = find(b);

        if(a==b) {return false;}

        if(root[a] < root[b]) //size small into big
        {
            root[a] += root[b];
            root[b] = a;
        }
        else
        {
            root[b] += root[a];
            root[a] = b;
        }

        return true;
    }
};


int main()
{
    int n,m;
    cin >> n >> m;

    DSU D; D.init(n);
    vector<tuple<int,int,int>> edges; 

    for(int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        edges.pb(mp(c, a-1, b-1));
    }

    sort(edges.begin(), edges.end());
    ll ans = 0;
    int node = 0;

    for(auto add : edges)
    {
        int cost, a, b; tie(cost, a, b) = add;
        
        if(D.unite(a,b))
        {
            ans += cost;
            node++;
        }
    }

    if(node != n-1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << ans;
    }

}
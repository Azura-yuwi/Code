#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

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
    int n; cin >> n;
    vector<pair<int,pair<int,int>>> byx;
    DSU D; D.init(n);
    vector<tuple<ll,int,int>> edges;

    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        byx.pb(mp(a,mp(b,i))); //x, y, node
    }

    sort(byx.begin(), byx.end());

    if(n <= 1000)
    {
        for(int i = 0; i < byx.size(); i++)
        {
            for(int j = i+1; j < byx.size(); j++)
            {
                ll xdist = (ll)(byx[i].f - byx[j].f);
                ll ydist = (ll)(byx[i].s.f - byx[j].s.f);
                ll cost = xdist*xdist + ydist*ydist;
                edges.pb(make_tuple(cost, byx[i].s.s, byx[j].s.s));
            }
        }
    }
    else
    {
        vector<pair<int,int>> listx[11]; //x, node

        for(int i = 0; i < byx.size(); i++)
        {
            listx[byx[i].s.f].pb(mp(byx[i].f, byx[i].s.s));
        }

        int at[11];

        for(int i = 0; i < 11; i++)
        {
            at[i] = 0;
        }

        for(int i = 0; i < byx.size(); i++)
        {
            int x = byx[i].f; int y = byx[i].s.f; int node = byx[i].s.s;
            at[y]++;

            for(int gety = 0; gety <= 10; gety++)
            {
                if(at[gety] >= listx[gety].size())
                {
                    continue;
                }

                int getx = listx[gety].at(at[gety]).f;
                int node2 = listx[gety].at(at[gety]).s;
                ll cost = ((ll)getx - x)*((ll)getx-x) + (gety - y)*(gety-y);

                edges.pb(make_tuple(cost, node, node2));
            }
        }
    }

    sort(edges.begin(), edges.end());
    ll ans = 0;

    for(auto add : edges)
    {
        ll cost; int a, b; tie(cost, a, b) = add;
        
        if(D.unite(a,b))
        {
            ans += cost;
        }
    }

    cout << ans;
}
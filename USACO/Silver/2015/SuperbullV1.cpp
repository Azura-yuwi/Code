//prim: dense graph

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int n;
vector<pair<ll, int>> adj[2001];
ll id[2001];

ll prim()
{
    bool visit[n];
    ll dM[n]; // min dist to edge in mst

    for(int i = 0; i < n; i++)
    {
        dM[i] = 1; //max here sicne we're all negatives rn
        visit[i] = false;
    }

    dM[0] = 0;
    ll total = 0;

    for(int i = 0; i < n; i++)
    {
        int v = -1;
        for(int j = 0; j < n; j++)
        {
            if(!visit[j] && (v == -1 || dM[v] > dM[j])) //exists edge with shorter distance to mst
            {
                v = j;
            }
        }

        visit[v] = true;
        total += dM[v];

        for(auto j : adj[v])
        {
            dM[j.s] = min(j.f, dM[j.s]);
        }
    }

    return total;
}

int main()
{
    ifstream fin("superbull.in");
    ofstream fout("superbull.out");
    fin >> n;

    for(int i = 0; i < n; i++)
    {
        fin >> id[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            ll sc = (-1)*(id[i]^id[j]); //turn to minimum spanning tree
            adj[i].pb(mp(sc, j));
            adj[j].pb(mp(sc, i));
        }
    }

    ll ans = prim();

    fout << (-1)*ans << endl;
}
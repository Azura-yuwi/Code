//prim: sparse graph implementation
//(not really for this q tho)
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
    ll min[n]; // min dist to edge in mst

    for(int i = 0; i < n; i++)
    {
        min[i] = 1; //max here sicne we're all negatives rn
        visit[i] = false;
    }

    min[0] = 0;
    set<pair<ll, int>> q; 
    q.insert(mp(0,0)); //distance, vertex
    ll total = 0;

    for(int i = 0; i < n; i++)
    {
        if(q.empty())
        {
            return -1;
        }

        int get = q.begin() -> s; //next vertex to go to
        visit[get] = true;
        total += q.begin() -> f; //add distance to this edge
        q.erase(q.begin()); // get rid of all distances of this vertexes now

        for(auto to : adj[get]) 
        {
            if(!visit[to.s] && to.f < min[to.s]) //can update the distance of this node to the mst
            {
                q.erase(mp(min[to.s], to.s));
                min[to.s] = to.f;
                q.insert(mp(to.f, to.s));
            }
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
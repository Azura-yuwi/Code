#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<pair<int,int>> adj[200000];
vector<pair<ll,ll>> costs;
ll walks[200000];
pair<int,int> lca[200000]; //i-1 and i, i and i+1
vector<int> eulerTour;
int in[200000];
ll cnt[200000];
ll toAdd;

void dfs(int at, int p)
{
    in[at] = eulerTour.size();
    eulerTour.pb(at);

    for(pair<int,int> get : adj[at])
    {
        if(get.f != p)
        {
            dfs(get.f, at);
            eulerTour.pb(at);
        }
    }
}

template<class T> struct segment_tree
{
    const T INF = mp(1e9, 1e9);
    int n; vector<pair<int,int>> segTree;

    T func(T a, T b) //function of segment tree
    {
        return min(a,b);
    }

    void init(int size)
    {
        n = size;
        segTree.assign(2*n, INF);
    }

    void upd(int p, T v)
    {
        segTree[p += n] = v;

        for(p /= 2; p > 0; p /= 2)
        {
            segTree[p] = func(segTree[2*p], segTree[2*p+1]);
        }
    }

    int query(int l, int r) //interval [l, r)
    {
        T ans = mp(1e9 + 10, 0);

        for(l += n, r += n; l < r; l /= 2, r /= 2) 
        {
            if(l&1) //&1 true -- > right component; left element + l < r --> you can move up the tree
            {
                ans = func(ans, segTree[l++]); //same as func(ans, segTree[l]); l++
            }

            if(r&1) //remember r), if r is right element -> right bound is an left element; r = left element --> you can move up the tree;
            {
                ans = func(ans, segTree[--r]); //same as func(ans, segTree[r-1]); r--;
            }
        }

        return ans.s;
    }
};

segment_tree<pair<int,int>> tree;

void dfs1(int at, int p)
{
    int total = 0;

    for(pair<int,int> get : adj[at])
    {
        if(get.f != p)
        {
            dfs1(get.f, at);

            walks[get.s] += toAdd;
            total += toAdd;
            toAdd = 0;            
            total -= cnt[at];
            cnt[at] = 0;            
        }
    }

    if(lca[at].f != at)
    {
        total++;
        cnt[lca[at].f]++;
    }

    if(lca[at].s != at)
    {
        total++;
        cnt[lca[at].s]++;
    }
    toAdd = total;
}


int main()
{
    int n; cin >> n;

    for(int i = 0; i < n-1; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        ll c1,c2; cin >> c1 >> c2;
        adj[a].pb(mp(b,i));
        adj[b].pb(mp(a,i));
        costs.pb(mp(c1, c2));
        walks[i] = 0;
        cnt[i] = 0;
    }

    cnt[n-1] = 0;
    toAdd = 0;
    dfs(0,0);
    tree.init(eulerTour.size());

    for(int i = 0; i < eulerTour.size(); i++)
    {
        tree.upd(i, mp(in[eulerTour[i]], eulerTour[i]));
    }

    lca[0] = mp(0,0);
    
    for(int i = 1; i < n-1; i++)
    {
        int l = in[i]; int r = in[i+1];

        if(l > r)
        {
            swap(l,r);
        }

        lca[i] = mp(lca[i-1].s, tree.query(l,r+1));
    }

    lca[n-1] = mp(lca[n-2].s, n-1);

    dfs1(0,0);

    ll total = 0;

    for(int i = 0; i < n-1; i++)
    {
        total += min(costs[i].s, costs[i].f*walks[i]);
    }

    cout << total << endl;
}
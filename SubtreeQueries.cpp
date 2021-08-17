//USACO Euler Tour Technique
//CSES Tree Algorthms
//DFS + segtree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_tuple

ll val[200005];
int en[200005]; // end of subtree
int st[200005]; //start = pos
vector<int> adj[200005];
int on;

void dfs(int src, int p)
{
    st[src] = on++;
    for(int i : adj[src])
    {
        if(i != p)
        {
            dfs(i, src);
        }
    }

    en[src] = on - 1; 
    
}

template<class T> struct segment_tree
{
    const T INF = 0;
    int n; vector<T> segTree;

    T func(T a, T b)
    {
        return a+b;
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

    T query(int l, int r) //interval [l, r)
    {
        T ans = INF;
    
        for(l += n, r += n; l < r; l /= 2, r /= 2) 
        {
            if(l&1)
            {
                ans = func(ans, segTree[l++]); //same as func(ans, segTree[l]); l++
            }

            if(r&1)
            {
                ans = func(ans, segTree[--r]); //same as func(ans, segTree[r-1]); r--;
            }
        }

        return ans;
    }
};

segment_tree<ll> tree;

int main()
{
    int n,q; cin >> n >> q;

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    on = 0;
    dfs(0,0);

    tree.init(n);

    for(int i = 0; i < n; i++)
    {
        tree.upd(st[i], val[i]);
    }

    for(int i = 0; i < q; i++)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int a; ll b; cin >> a >> b;
            tree.upd(st[a-1], b);
        }
        else
        {
            int a; cin >> a;
            cout << tree.query(st[a-1], en[a-1]+1) << endl;
        }
    }

}
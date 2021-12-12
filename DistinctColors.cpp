//USACO Guide Euler Tour Technique
//CSES Tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

template<class T> struct segment_tree
{
    const T INF = 0; int n; vector<T> segTree;
    void init(int size) { n = size; segTree.assign(2*n, INF); }

    T func(T a, T b) 
    { 
        return a+b; 
    }

    void upd(int p, T v)
    {
        segTree[p += n] = v;
        for(p /= 2; p > 0; p /= 2) { segTree[p] = func(segTree[2*p], segTree[2*p+1]); }
    }

    T query(int l, int r) //interval [l, r)
    {
        T ans = INF;
        for(l += n, r += n; l < r; l /= 2, r /= 2) 
        {
            if(l&1) { ans = func(ans, segTree[l++]); } //same as func(ans, segTree[l]); l++
            if(r&1) { ans = func(ans, segTree[--r]); } //same as func(ans, segTree[r-1]); r--;
        }
        return ans;
    }
};

segment_tree<int> tree;
vector<int> adj[200005];
int at = 0;
int st[200005];
int en[200005];
map<int,int> recent;
int ind[200005];
int sol[200005];

void dfs(int node, int p)
{
    st[node] = at; ind[at] = node; at++;

    for(int to : adj[node])
    {
        if(to != p)
        {
            dfs(to, node);
        }
    }

    en[node] = at; //exclusive
}

int main()
{
    int n; cin >> n;
    int val[n];

    tree.init(n);

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b; a--;b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(0,0);

    for(int i = n-1; i >= 0; i--)
    {
        int get = ind[i];

        if(recent.find(val[get]) != recent.end())
        {
            tree.upd(recent[val[get]], 0);
        }

        recent[val[get]] = i;
        tree.upd(i, 1);

        sol[get] = tree.query(i, en[get]);
    }

    for(int i = 0; i < n; i++)
    {
        cout << sol[i] << " ";
    }
}
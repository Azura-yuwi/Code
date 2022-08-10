//DP on Trees all roots
//CodeForces
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n;
ll subTree[200005];
ll pts[200005];
ll rootPts[200005];
vector<int> adj[200005];

void dfs1(int at, int p)
{
    subTree[at] = 1;
    pts[at] = 0;

    for(int to : adj[at])
    {
        if(to != p)
        {
            dfs1(to, at);
            subTree[at] += subTree[to];
            pts[at] += pts[to];
        }
    }

    pts[at] += subTree[at];
}

void dfs2(int at, int p)
{
    if(at != 0)
    {
        ll sP = n - subTree[at];
        ll pP = rootPts[p] - subTree[at] - pts[at];
        rootPts[at] = pts[at] + pP + sP;
    }
    
    //cout << "at " << at << " p " << p << " " << rootPts[at] << " " << rootPts[p] << endl;

    for(int to : adj[at])
    {
        if(to != p)
        {
            dfs2(to, at);
        }
    }

}

int main()
{
    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b; a--;b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs1(0,0);
    rootPts[0] = pts[0];
    dfs2(0,0);

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, rootPts[i]);
    }

    cout << ans;

}
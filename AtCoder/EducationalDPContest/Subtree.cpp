//DP on Trees all roots

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n; ll m;
vector<int> adj[100005];
ll dp[100005]; //ways to color subtree if i was colored black
ll rt[100005];

void dfs(int at, int p)
{
    dp[at] = 1;

    for(int to : adj[at])
    {
        if(to != p)
        {
            dfs(to, at);
            dp[at] *= (dp[to]+1); dp[at] %= m;
        }
    }
}

void dfs2(int at, int p)
{
    // Solution Way
    rt[at] = 1;

    for(int to : adj[at]) //will update dp to become "child node" so works out in dfs here
    {
        rt[at] *= dp[to]+1; rt[at] %= m;
    }

    int sz = adj[at].size();
    ll pre[sz];
    ll post[sz];

    for(int i = 0; i < sz; i++)
    {   
        pre[i] = dp[adj[at][i]]+1; post[i] = dp[adj[at][i]]+1;
    }

    for(int i = 1; i < sz; i++)
    {
        pre[i] *= pre[i-1]; pre[i] %= m;
    }

    for(int i = sz-2; i >= 0; i--)
    {
        post[i] *= post[i+1]; post[i] %= m;
    }

    for(int i = 0; i < sz; i++)
    {
        int to = adj[at][i];
        if(to != p)
        {
            dp[at] = 1;
            if(i > 0) { dp[at] *= pre[i-1];}
            if(i < sz-1) { dp[at]*= post[i+1]; }

            dp[at] %= m;

            dfs2(to, at);
        }
    }

}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n-1; i++)
    {
        int a,b; cin >> a >> b; a--;b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(0,-1); rt[0] = dp[0];
    dfs2(0, -1);

    for(int i = 0; i < n; i++)
    { 
        cout << rt[i] << endl;
    }
}
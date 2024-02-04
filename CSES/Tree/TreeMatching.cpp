//CSES Tree Algorithms
//USACO DP on Trees
//DP method (there is another greedy method)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int n;
vector<int> adj[200005];
int dp[200005][2];

void dfs(int node, int p)
{
    dp[node][1] = 0;

    for(int to : adj[node])
    {
        if(to != p)
        {
            dfs(to, node);
            dp[node][1] += dp[to][0];
        }
    }

    dp[node][0] = dp[node][1];

    for(int to : adj[node])
    {
        if(to != p)
        {
            dp[node][0] = max(dp[node][0], dp[node][1] - dp[to][0] + dp[to][1] + 1);
        }
    }

    return;
}



int main()
{
    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(0, -1);
    cout << dp[0][0];
}
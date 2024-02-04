//CSES Tree Algorithms

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[200005];
int dp[200005];

void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        dp[i] = 0;
    }
}

void dfs(int v, int pv)
{
    for(int to : adj[v])
    {
        if(to != pv)
        {
            dfs(to, v);
            dp[v] += (dp[to]+1);
        }
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int get; cin >> get;
        adj[get-1].pb(i);
    }

    init(n);

    dfs(0,0);

    for(int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }


}
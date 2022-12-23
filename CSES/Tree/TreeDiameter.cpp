#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[200005];

int dp[200005];
int ans;

void dfs(int at, int p)
{
    dp[at] = 0;
    int max1 = 0; int max2 = 0;

    for(int to : adj[at])
    {
        if(to != p)
        {
            dfs(to, at);
            
            if(max1 > dp[to])
            {
                max2 = max(max2, dp[to]);
            }
            else
            {
                max2 = max1;
                max1 = dp[to];
            }
        }
    }

    dp[at] = max1 + 1;
    ans = max(ans, max1 + max2 + 1);
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b; a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ans = 0;
    dfs(0,-1);

    cout << (ans-1); 
}
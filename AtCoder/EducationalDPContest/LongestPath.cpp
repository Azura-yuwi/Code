#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,m; cin >> n >> m;

    vector<int> adj[n];
    int in[n];
    int dp[n];

    for(int i = 0; i < n; i++)
    {
        in[i] = 0;
        dp[i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj[a].pb(b);
        in[b]++;
    }

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int at = q.front(); q.pop();

        for(int get : adj[at])
        {
            dp[get] = max(dp[get], dp[at] + 1);
            in[get]--;

            if(in[get] == 0)
            {
                q.push(get);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}
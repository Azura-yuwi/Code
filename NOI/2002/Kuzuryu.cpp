#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int n,m,k;
vector<pair<int,int>> adj[305];
ll dp[300][300][2];
const ll mx = INT_MAX;

void dfs(int p, int at)
{
    int children = 0;   

    for(auto get : adj[at])
    {
        int to, pain; tie(to, pain) = get;
        if(to != p) dfs(at, to);
    }

    for(auto get : adj[at])
    {
        int to, pain; tie(to, pain) = get;

        if(to != p)
        {
            if(children == 0)
            {
                for(int w = k; w >= 0; w--)
                {
                    if(w > 0) dp[at][w][0] = min(min(dp[to][w-1][0], mx - pain) + pain, dp[to][w-1][1]);

                    if(m == 2) dp[at][w][1] = min(dp[to][w][0], min(dp[to][w][1], mx - pain) + pain);
                    else dp[at][w][1] = min(dp[to][w][0], dp[to][w][1]);
                }

                children++;
            }
            else
            {
                for(int w = k; w >= 0; w--)
                {
                    ll ans0 = mx;
                    ll ans1 = mx;

                    for(int x = w; x >= 0; x--)
                    {
                        if(dp[at][w-x][0] != mx)
                        {
                            ans0 = min(ans0, min(dp[at][w - x][0] + min(dp[to][x][0], mx - pain - dp[at][w-x][0]) + pain, dp[at][w-x][0] + min(dp[to][x][1], mx - dp[at][w-x][0])));
                        }

                        if(dp[at][w-x][1] != mx)
                        {
                            if(m==2) ans1 = min(ans1, min(dp[at][w-x][1] + min(dp[to][x][0], mx - dp[at][w-x][1]), dp[at][w-x][1] + min(dp[to][x][1], mx - dp[at][w-x][1] - pain) + pain));
                            else ans1 = min(ans1, min(dp[at][w-x][1] + min(dp[to][x][0], mx - dp[at][w-x][1]), dp[at][w-x][1] + min(dp[to][x][1], mx - dp[at][w-x][1]))); 
                        }
                    }

                    dp[at][w][0] = ans0; dp[at][w][1] = ans1;
                }
            }
        }
    }

    if(children == 0) //leaf node
    {
        dp[at][0][1] = 0;
        dp[at][1][0] = 0;
    }
}


int main()
{
    cin >> n >> m >> k;
    
    for(int i = 0; i < n-1; i++)
    {
        int a,b,c; cin >> a >> b >> c; a--;b--;
        adj[a].pb(mp(b,c)); adj[b].pb(mp(a,c));
    }

    if(m + k - 1 > n) 
    {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j][0] = mx;
            dp[i][j][1] = mx;
        }
    }

    dfs(0,0);

    cout << dp[0][k][0];
}
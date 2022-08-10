#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    int n, W; cin >> n >> W;
    int w[n]; ll v[n];

    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    ll dp[W+1];

    for(int i = 0; i <= W; i++)
    {
        dp[i] = -1;
    }

    dp[0] = 0; dp[w[0]] = v[0];

    for(int i = 1; i < n; i++)
    {
        for(int j = W-w[i]; j >= 0; j--)
        {
            if(dp[j] == -1)
            {
                continue;
            }

            dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
        }
    }

    ll ans = 0;

    for(int i = 0; i <= W; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;

}
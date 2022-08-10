//Range DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n; cin >> n;
    ll val[n];
    ll pre[n+1];
    pre[0] = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> val[i]; pre[i+1] = pre[i] + val[i];
    }

    ll dp[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = LLONG_MAX;
            }
        }
    }

    for(int l = 1; l < n; l++)
    {
        for(int st = 0; st < n-l; st++)
        {
            for(int k = st; k < st+l; k++)
            {
                dp[st][st+l] = min(dp[st][st+l], dp[st][k] + dp[k+1][st+l]);
            }

            dp[st][st+l] += pre[st+l+1] - pre[st];
            //cout << "start " << st << " lenght " << l << " dp " << dp[st][st+l] << " " << pre[st+l+1]-pre[st] << endl;
        }
    }

    cout << dp[0][n-1];
}
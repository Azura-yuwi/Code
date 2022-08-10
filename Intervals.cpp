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
    ll a[n][n];
    ll pre[n][n+1]; //pre[i][j+1] = right endpoint is at i, sum of all a[j][i] such that j <= i
    ll rpre[n][n];
    //ll post[n][n+1];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int l,r; ll b; cin >> l >> r >> b; l--; r--;
        a[l][r] += b;
    }

    
    for(int i = 0; i < n; i++)
    {
        pre[i][0] = 0;

        for(int j = 0; j < n; j++)
        {
            pre[i][j+1] = pre[i][j] + a[j][i];
        }
    }

    for(int i = 0; i < n; i++)
    {
        rpre[i][i] = 0;

        for(int j = i+1; j < n; j++)
        {
            rpre[i][j] = rpre[i][j-1] + pre[j][i+1];
        }
    }

    /*for(int i = 0; i < n; i++)
    {
        post[i][n] = 0;

        for(int j = n-1; j >= 0; j--)
        {
            post[i][j] = post[i][j+1] + a[i][j];
        }
    }*/

    /*ll dp[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j <= i)
            {
                if(i == 0) dp[i][j] = pre[i][j+1];
                else dp[i][j] = dp[i-1][j] + pre[i][j+1];
            }
            else 
            {
                dp[i][j] = 0;
            }

            cout << dp[i][j] << " ";
        }

        cout << endl;
    }*/

    
    ll dp[n][2];

    for(int i = 0; i < n; i++)
    {
        if(i == 0) dp[i][1] = a[0][0];
        else dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + pre[i][i+1];

        dp[i][0] = 0;

        for(int j = 0; j < i; j++)
        {
            //dp[i][0] = max(dp[i][0], dp[j][1] + pre[i][j+1]);
            dp[i][0] = max(dp[i][0], dp[j][1] + rpre[j][i]);
            //dp[i][0] = max(dp[i][0], dp[i-1][0] + a[i][j+1]);
        }

        //cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    ll ans = 0;

    for(int i = 0; i < 2; i++)
    {
        ans = max(ans, dp[n-1][i]);
    }

    cout << ans;
}
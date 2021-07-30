#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    int mod = 1e9 + 7;

    int val[n];
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int dp[n][m];



    if(val[0] != 0)
    {
        //cout << " ENTER " << endl;

        for(int i = 0; i < m; i++)
        {
            dp[0][i] = 0;
        }

        dp[0][val[0]-1] = 1;

        //cout << dp[0][val[0] - 1] << endl;
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < n; i++)
    {
        //cout << i << " " << val[i] << endl;

        if(val[i] != 0)
        {
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = 0;
            }

            for(int j = max(0, val[i]-2); j < min(m, val[i] + 1); j++)
            {
                dp[i][val[i]-1] += dp[i-1][j];
                dp[i][val[i]-1] = dp[i][val[i]-1]%mod;
            }

            //cout << i << " " << val[i]-1 << " " << dp[i][val[i]-1] << endl;
        }
        else
        {
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = 0;
                
                for(int k = max(0, j-1); k < min(m, j+2); k++)
                {
                    dp[i][j] += dp[i-1][k]; 
                    dp[i][j] = dp[i][j]%mod;
                }

                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }

    }

    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        ans += dp[n-1][i];
        ans = ans%mod;
    }

    cout << ans;
}
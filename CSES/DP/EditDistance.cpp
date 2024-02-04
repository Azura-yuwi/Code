//CSES Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    ll dp[n+1][m+1];

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;

            if(s[i-1] == t[j-1])
            {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
            else
            {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            }

            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    cout << dp[n][m];
}

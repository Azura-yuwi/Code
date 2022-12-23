//CSES Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a, b;
    cin >> a >> b;

    int dp[a+1][b+1];

    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;

                for(int n = 1; n < i/2 + 1; n++)
                {
                    dp[i][j] = min(dp[i][j], dp[n][j] + dp[i-n][j]);
                }

                for(int m = 1; m < j/2 + 1; m++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[i][j-m]);
                }

                dp[i][j]++;
            }
        }
    }

    cout << dp[a][b];
}
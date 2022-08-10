#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    int n; cin >> n;
    int val[n][3];
    int dp[n][3];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i][0] >> val[i][1] >> val[i][2];
    }

    dp[0][0] = val[0][0];
    dp[0][1] = val[0][1];
    dp[0][2] = val[0][2];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            dp[i][j] = val[i][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
        }
    }

    cout << max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll mod = 1e9 + 7;
    int n,m,x; cin >> n >> m >> x;

    if(n>m)
    {
        cout << 0;
        return 0;
    }

    ll dp[n+1][n+1][m];

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;

    if(x != 1) {dp[0][0][0] = 1;} 
    else { dp[0][0][0] = 0;}

    for(int v = 1; v < m; v++)
    {
        for(int i = 0; i <= min(v+1,n); i++) //lefts
        {
            for(int j = 0; j <= i; j++) //rights
            {
                if(i <= v && v != (x-1)) {dp[i][j][v] = dp[i][j][v-1];}
                else {dp[i][j][v] = 0;}
                
                if(i > 0 && i > j) dp[i][j][v] += dp[i-1][j][v-1];
                dp[i][j][v] %= mod;

                if(i <= v && j > 0 && v != (x-1)) dp[i][j][v] += dp[i][j-1][v-1];
                dp[i][j][v] %= mod;

                if(i > 0 && j > 0) dp[i][j][v] += dp[i-1][j-1][v-1];
                dp[i][j][v] %= mod;
            }
        }
    }

    ll ans = dp[n][n][m-1]; 

    for(int i = 1; i <= n; i++)
    {
        ans *= i; //integer overflows here
        ans %= mod;
    }

    cout << ans << endl;
}
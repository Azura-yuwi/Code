//CSES Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;

    ll val[n];
    ll pre[n+1];
    pre[0] = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
        pre[i+1] = pre[i] + val[i];
    }

    ll dp[n][n]; // first person max val if [start at][num of elements (-1 technically)]

    for(int i = 0; i < n; i++)
    {
        dp[0][i] = val[i];
    }

    for(int i = 1; i < n; i++) // i = num elements - 1
    {
        for(int j = 0; j < n - i; j++)
        {
            //cout << "FROM " << i << " " << j << endl;
            //cout << "INTERVAL TOTAL " << pre[j+i+1] << " " << pre[j] << " " << (pre[j+i+1] - pre[j]) << endl;
            //cout << dp[i-1][j] << " " << dp[i-1][j+1] << endl;
            dp[i][j] = pre[j+i+1] - pre[j] - min(dp[i-1][j], dp[i-1][j+1]);

            //cout << dp[i][j] << endl;
        }
    }

    cout << dp[n-1][0];
}
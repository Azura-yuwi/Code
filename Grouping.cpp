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
    ll tpts[(1<<n)]; //precompute points each set has
    ll dp[(1<<n)];
    ll pt[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> pt[i][j];
        }
    }

    for(int i = 0; i < (1<<n); i++)
    {
        tpts[i] = 0;
        dp[i] = 0;

        for(int j = 0; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(i&(1<<j) && (i&(1<<k)))
                {
                    tpts[i] += pt[j][k];
                }
            }
        }
    }

    for(int i = 0; i < (1<<n); i++)
    {
        for(int j = i; j > 0; j = ((j-1)&i)) //iterate through subsets of i
        {
            dp[i] = max(dp[i], dp[i-j] + tpts[j]);
        }
    }

    cout << dp[(1<<n)-1];

}
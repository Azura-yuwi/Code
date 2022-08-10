#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,k; cin >> n >> k;
    int cost[n];
    int dp[n];

    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = i-1; j >= max(i-k, 0); j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(cost[i] - cost[j]));
        }
    }

    cout << dp[n-1];
}
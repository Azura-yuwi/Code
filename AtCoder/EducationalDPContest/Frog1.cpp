#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n; cin >> n;
    int cost[n];
    int dp[n];

    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    dp[0] = 0;
    dp[1] = abs(cost[0]- cost[1]);

    for(int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i-1] + abs(cost[i-1] - cost[i]), dp[i-2] + abs(cost[i-2] - cost[i]));
    }

    cout << dp[n-1];
}
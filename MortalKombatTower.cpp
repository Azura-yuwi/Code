#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int solve()
{
    int n; cin >> n;
    bool h[n];
    int dp[n][2];

    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
        dp[i][0] = n;
        dp[i][1] = n;
    }
    
    dp[0][0] = h[0]; //start with 1 turn
    dp[1][0] = h[0] + h[1]; //start with 2 turns

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i][0], dp[i-1][1] + h[i]); //friend take 1 turn
        if(i > 1) dp[i][0] = min(dp[i][0], dp[i-2][1] + h[i-1] + h[i]); //friend take 2 turns

        dp[i][1] = min(dp[i][1], dp[i-1][0]); //you take 1 turn
        if(i > 1) dp[i][1] = min(dp[i][1], dp[i-2][0]); //you take 2 turns
    }

    return min(dp[n-1][0], dp[n-1][1]);
}

int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        cout << solve() << endl;
    }
}
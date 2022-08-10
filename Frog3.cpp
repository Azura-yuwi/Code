#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n; ll c; cin >> n >> c;
    ll h[n];

    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    ll dp[n];

    for(int i = 0; i < n; i++)
    {
        dp[i] = LLONG_MAX;
    }

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j] + (h[i] - h[j])*(h[i] - h[j]) + c);
        }
    }

    cout << dp[n-1];


}
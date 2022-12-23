#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    int s,t,m; cin >> s >> t >> m;

    bool stone[n+1];
    int dp[n+1];

    for(int i = 0; i <= n; i++)
    {
        stone[i] = false;
    }

    for(int i = 0; i < m; i++)
    {
        int get; cin >> get; stone[get] = true;
    }

    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        dp[i] = 101;

        for(int j = i-t; j <= i-s; j++)
        {
            if(j < 0) continue; 

            dp[i] = min(dp[i], dp[j]);
        }

        if(stone[i])
        {
            dp[i]++;
        }
    }

    int minimum = INT_MAX;

    for(int i = n; i > n-t; i--)
    {
        minimum = min(minimum, dp[i]);
    }

    cout << minimum;

}
//using custom sort functions

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
//#define s second

int main()
{
    int n; cin >> n;
    int w[n], s[n], p[n]; ll v[n]; 
    ll dp[20002];

    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> s[i] >> v[i]; p[i] = i;
    }

    for(int i = 0; i < 20001; i++)
    {
        dp[i] = 0;
    }

    sort(p, p+n, [&] (const int &a, const int &b)
    {
        return min(s[b], s[a] - w[b]) < min(s[a], s[b] - w[a]); 
        //if true, a should come before b to maximize above weight
    });

    for(int k = 0; k < n; k++)
    {
        int j = p[k];

        for(int i = s[j]+w[j]; i >= w[j]; i--)
        {
            dp[i] = max(dp[i], dp[i-w[j]] + v[j]);
        }
    }

    ll ans = 0;

    for(int i = 0; i < 20001; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    
}

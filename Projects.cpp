//CSES Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair

int main()
{
    int n;
    cin >> n;
    pair<int, pair<int, ll>> proj[n+1]; //end, start, val;

    proj[0] = mp(0, mp(0,0));

    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        proj[i] = mp(b, mp(a,c));
    }

    sort(proj, proj + (n+1));

    int makeint[n+1];

    for(int i = 0; i <= n; i++)
    {
        makeint[i] = proj[i].f;
    }

    ll dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        int j = lower_bound(makeint, makeint+(i), proj[i].s.f) - makeint;

        //cout << i << " " << j << endl;
       // cout << dp[i-1] << " " << dp[j-1] << " " << proj[i].s.s << endl;
        //cout << endl;
        dp[i] = max(dp[i-1], dp[j-1] + proj[i].s.s);
    }

    cout << dp[n];
}
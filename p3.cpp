#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n; cin >> n;
    ll loc[n];
    ll pre[n+1];
    pre[0] = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> loc[i]; 
    }

    sort(loc, loc + n);

    for(int i = 0; i < n; i++)
    {
        pre[i+1] = pre[i] + loc[i];
    }

    int t; cin >> t;

    for(int q = 0; q < t; q++)
    {
        ll a, b; cin >> a >> b;
        int i = (b*n)/(a+b);
        ll ans = a*loc[i]*i - a*(pre[i]);
        ans += b*(pre[n] - pre[i]) - b*loc[i]*(n-i);
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int k,m,n; cin >> k >> m >> n;
    pair<int,int> fields[k];
    int cows[m];

    for(int i = 0; i < k; i++)
    {
        int a,b; cin >> a >> b;
        fields[i] = mp(a,b);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> cows[i];
    }

    sort(fields, fields + k);
    sort(cows, cows + m);

    pair<int,int> val[k];
    int p = 0;

    for(int i = 0; i < k; i++)
    {
        while(p < m-1 && cows[p+1] < fields[i].f)
        {
            p++;
        }

        int dist = abs(fields[i].f - cows[p]);

        if(p+1 < m)
        {
            dist = min(dist, abs(fields[i].f - cows[p+1]));
        }

        val[i] = mp(fields[i].f - dist, fields[i].f + dist);
    }

    vector<ll> taste;

    int at = 0;
    while(at < k)
    {
        ll res = 0;
        int end = val[at].s;
        while(at < k && val[at].f < end)
        {
            res += fields[at].s;
            at++;
        }

        taste.pb(res);
    }

    sort(taste.begin(), taste.end(), greater<ll>());

    ll ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        ans += taste[i];
    }

    cout << ans;
}
//CSES Geometry
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
    pair<ll,ll> pnts[n];

    for(int i = 0; i < n; i++)
    {
        ll a,b; cin >> a >> b;
        pnts[i] = mp(a,b);
    }

    ll sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += pnts[i].f*pnts[(i+1)%n].s - pnts[i].s*pnts[(i+1)%n].f;
    }

    sum = abs(sum);

    cout << sum;
}
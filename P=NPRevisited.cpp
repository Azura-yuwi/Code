#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

ll mod = 1e9+7;
ll power = 1e9+5;

ll invMod(ll n) //fermat little a^(p-2)
{
    ll base = n;
    ll on = power;
    ll ans = 1;

    while(on > 0) //binary exponentation
    {
        if(on%2 == 1)
        {
            ans *= base; ans %= mod;
        }

        base *= base; base %= mod;
        on /= 2;
    }

    return ans;
}

int main()
{
    int t; cin >> t; vector<pair<int,int>> queries;
    int n = 0; int p = 0;

    for(int i = 0; i < t; i++)
    {
        int a,b; cin >> a >> b; queries.pb(mp(a,b));
        n = max(n, a); p = max(b,p);
    }

    vector<ll> fact; 
    vector<ll> inv;

    fact.pb(0); inv.pb(0);
    fact.pb(1); inv.pb(1);
    ll prod = 1;

    //precompute
    for(int i = 2; i <= (n+p+1); i++)
    {
        prod *= i; prod %= mod;
        fact.pb(prod);
        inv.pb(invMod(prod));
    }

    for(int i = 0; i < t; i++)
    {
        int a,b; tie(a,b) = queries[i];
        prod = 1;

        for(int i = 1; i <= a; i++)
        {
            prod *= fact[i+b+1]; prod %= mod;
            prod *= inv[i+1]; prod %= mod;
        }

        cout << prod << endl;
    }
}
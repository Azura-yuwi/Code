#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

const ll mod = 1e9 + 7;
ll fact[100005];
ll inv[100005];

ll invMod(ll n) //fermat little a^(p-2)
{
    ll base = n; ll on = mod-2; ll ans = 1;

    while(on > 0) //binary exponentation
    {
        if(on%2 == 1) { ans *= base; ans %= mod; }
        base *= base; base %= mod;
        on /= 2;
    }

    return ans;
}

void fillFact(int n)
{
    fact[0] = 1;
    inv[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = invMod(fact[i]);
    }
}

ll binom(int n, int r)
{
    return ((((fact[n]*inv[r])%mod)*inv[n-r])%mod);
}

int main()
{
    int h,w,n; cin >> h >> w >> n;
    pair<int,int> wall[n];
    ll direct[n];

    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b; wall[i] = mp(a,b); direct[i] = 0;
    }

    fillFact(h+w-2);
    ll total = binom(h+w-2, w-1);

    sort(wall, wall+n);

    for(int i = 0; i < n; i++)
    {
        cout << wall[i].f << " " << wall[i].s << endl;
     }

    for(int i = 0; i < n; i++)
    {
        direct[i] = binom(wall[i].f + wall[i].s - 2, wall[i].f-1);

        for(int j = 0; j < i; j++)
        {
            if(wall[j].s <= wall[i].s)
            {
                ll sub = direct[i-1]*binom(wall[i].f+wall[i].s - wall[j].f - wall[j].s], wall[i].f - wall[i].s));
                direct[i] = (direct[i] - sub%mod + mod)%mod;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        total =  (total - direct[i] + mod)%mod;
    }

    cout << total;

}
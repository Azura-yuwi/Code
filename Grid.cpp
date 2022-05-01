//Grid2 on DMOJ

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

const ll mod = 1e9 + 7;
ll fact[200005];
ll inv[200005];

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

    //cout << "read" << endl;

    fillFact(h+w-2);

    //cout << "filled" << endl;
    ll total = binom(h+w-2, w-1);

    sort(wall, wall+n);

    for(int i = 0; i < n; i++)
    {
        direct[i] = binom(wall[i].f + wall[i].s - 2, wall[i].f-1);
       // cout << "init " << i << " " << direct[i] << endl;

        for(int j = 0; j < i; j++)
        {
            if(wall[j].s <= wall[i].s)
            {
                ll sub = direct[j]*binom(wall[i].f+wall[i].s - wall[j].f - wall[j].s, wall[i].f - wall[j].f);
                //cout << i << " " << j << " " << sub << endl;
                direct[i] = (direct[i] - sub%mod + mod)%mod;
            }
        }

        //cout << i << " direct " << direct[i] << endl;
    }

    //cout << endl;

    for(int i = 0; i < n; i++)
    {
        //cout << "direct " << direct[i] << endl;
        ll toSub = direct[i]*binom(h+w-wall[i].f - wall[i].s, h-wall[i].f);
        total =  (total - toSub%mod + mod)%mod;
    }

    cout << total;

}
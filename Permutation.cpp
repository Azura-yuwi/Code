#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

vector<ll> bit;
int sz;
const ll mod = 1e9+7;

void upd(int p, ll v)
{
    v = (v%mod + mod)%mod;

    for(; p <= sz; p += (p&(-p)))
    {
        bit[p] += v; bit[p] %= mod;
    }
}

ll query(int p)
{
    ll ans = 0;

    for(; p > 0; p -= (p&(-p)))
    {
        ans += bit[p]; ans %= mod;
    }

    return ans;
}

int main()
{
    int n; cin >> n;
    string seq; cin >> seq;
    bit.assign(n+1, 0); sz = n;

    for(int i = 1; i <= n; i++)
    {
        upd(i, 1);
    }

    for(int i = 0; i < n-1; i++)
    {
        if(seq[i] == '<')
        {
            for(int j = n; j > 0; j--)
            {
                ll val = query(j-1);
                upd(j, 2*val - query(j));
            }
        }
        else
        {
            for(int j = 1; j <= n; j++)
            {
                ll val = query(n) - query(j);
                upd(j, query(j-1) - query(j) + val);
            }
        }

        for(int i = 1; i <= n; i++)
        {
            cout << query(i) - query(i-1) << " ";
        }
        cout << endl;
    }

    cout << query(n);


    
}
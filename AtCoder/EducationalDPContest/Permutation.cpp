#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

const ll mod = 1e9+7;
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
    int n; string get; cin >> n >> get;
    bool sym[n-1];
    fillFact(3000);

    for(int i = 0; i < n-1; i++)
    {
        if(get[i] == '<') sym[i] = true;
        else sym[i] = false;
    }

    ll dp[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }

    for(int ad = 1; ad < n; ad++)
    {
        for(int l = 0; l < n-ad; l++)
        {
            if(!sym[l]) 
            {
                dp[l][l+ad] += dp[l+1][l+ad]; dp[l][l+ad] %= mod;
            }

            if(sym[l+ad-1])
            {
                dp[l][l+ad] += dp[l][l+ad-1]; dp[l][l+ad] %= mod;
            }

            for(int k = l+1; k < l+ad; k++)
            {
                if(sym[k-1] && !sym[k]) //can split here
                {
                    dp[l][l+ad] += (((dp[l][k-1]*dp[k+1][l+ad])%mod)*binom(ad, k-l))%mod; dp[l][l+ad] %= mod;
                }
            }

           // cout << l << " " << l+ad << " " << dp[l][l+ad] << endl;
        }
    }

    cout << dp[0][n-1];

}
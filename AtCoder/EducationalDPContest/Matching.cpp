//Bitmask DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

const int mod = 1e9 + 7;

int twos(int n)
{
    int ans = 0;
    while(n > 0)
    {
        if(n%2 == 1)
        {
            ans++;
        }

        n /= 2;
    }

    return ans;
}

int main()
{
    int n; cin >> n;
    int dp[(1<<n)];
    bool compat[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> compat[i][j];
        }
    }

    for(int i = 0; i < (1<<n); i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (1<<n); j++)
        {
           // cout << "i " << i << " j " << j << " " << twos(j) << endl;

            if(twos(j) != (i+1)) continue;
            
            for(int k = 0; k < n; k++)
            {
                if((j&(1<<k)) && compat[i][k])
                {
                    
                    dp[j] += dp[(j - (1<<k))];
                    dp[j] %= mod;
                    //cout << "compatible with " << k << " " <<dp[j] << " " << dp[(j - (1<<k))] << endl;
                }
            }
        }
    }

    cout << (dp[(1<<n)-1]%mod);

}
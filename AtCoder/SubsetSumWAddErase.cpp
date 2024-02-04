//Knapsack DP
//AtCoder Contest 321 F
// key in order of DP updating

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

const ll mod = 998244353;

int main()
{
    int q,k; cin >> q >> k;

    ll dp[k+1];

    for(int i = 0; i <= k; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for(int i = 0; i < q; i++)
    {
        char c; ll val;  cin >> c >> val;

        if(c == '+')
        {
            for(int j = k; j >= val; j--)
            {
                dp[j] += dp[j-val];
                dp[j] = (dp[j]+mod)%mod;
                
                //cout << dp[j] << " ";
            }
        }
        else
        {
            for(int j = val; j <= k; j++)
            {
                dp[j] -= dp[j-val];
                dp[j] = (dp[j]+mod)%mod;

                //cout << dp[j] << " ";
            }
        }

        //cout << endl;
        
        cout << dp[k] << endl;
    }
}
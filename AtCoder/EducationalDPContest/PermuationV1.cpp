#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
const ll mod = 1e9+7;
int main()
{
    int n; string get; cin >> n >> get;
    bool sym[n-1];

    for(int i = 0; i < n-1; i++)
    {
        if(get[i] == '<') sym[i] = true;
        else sym[i] = false;
    }

    ll dp[n];
    ll pre[n+1];
    ll post[n+1];

    for(int i = 0; i < n; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;
    pre[0] = 0;
    post[n] = 0;

    for(int i = 0; i < n; i++)
    {
        pre[i+1] = pre[i] + dp[i];
        post[n-i-1] = post[n-i] + dp[n-i-1];
    }

    for(int i = 1; i < n; i++)
    {
        if(sym[i-1])
        {
            for(int j = i; j > 0; j--)
            {
                dp[j] = pre[j]; //sum of all 1 to j-1
            }

            dp[0] = 0;
        }
        else
        {
            for(int j = 0; j < i; j++)
            {
                dp[j] = post[j]; //sum of n-1 to j (shifted to j+1 to n)
            }

            dp[i] = 0;
        }

        pre[0] = 0;
        post[n] = 0;

        for(int i = 0; i < n; i++)
        {
           // cout << dp[i] << " ";
            pre[i+1] = pre[i] + dp[i]; pre[i+1] %= mod;
            post[n-i-1] = post[n-i] + dp[n-i-1]; post[n-i-1] %= mod;
        }

       // cout << endl;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += dp[i]; ans %= mod;
    }

    cout << ans;

}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    ll mod = 1000000007;
    int test[t];
    int n = 0;
    
    for(int i = 0; i < t; i++)
    {
        cin >> test[i];
        test[i] = test[i] - 1;
        n = max(n, test[i]+1);
    }

    ll sep[n];
    ll fus[n];

    sep[0] = 1;
    fus[0] = 1;

    for(int i = 1; i < n; i++)
    {
        sep[i] = 4*sep[i-1] + fus[i-1];
        fus[i] = sep[i-1] + 2*fus[i-1];
        
        //cout << sep[i] << " " << fus[i] << " " << i << endl;

        sep[i] = sep[i]%mod;
        fus[i] = fus[i]%mod;

    }

    for(int i = 0; i < t; i++)
    {
        ll ans = sep[test[i]] + fus[test[i]];
        //cout << ans << endl;
        ans = ans%mod;
        cout << ans << endl;
    }
}
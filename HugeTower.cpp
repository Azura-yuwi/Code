#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool increase(ll const& p1, ll const& p2)
{
    return p1 > p2;
}

ll mod = 1000000009;

int main()
{
    ll n, d;
    cin >> n >> d;
    ll block[n+1];

    for (int i = 0; i < n; i++)
    {
        cin >> block[i];
    }

    block[n] = LLONG_MIN;
    ll work[n];

    sort(block, block + (n+1), increase);
    
    int point = 0;

    for(int i = 0; i < n; i++)
    {
        while(block[i] <= d+block[point])
        {
            point++;
        }

        work[i] = point - i;
    }

    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        ans *= work[i];
        ans = ans%mod;
        //cout << ans << " " << work[i] << endl;
    }
    
    cout << ans;

    return 0;
}


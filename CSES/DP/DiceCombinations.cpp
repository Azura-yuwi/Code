#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1000000007;

int main()
{
    ll n;
    cin >> n;
    ll num[n+1];

    num[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        if(i <= 6)
        {
            num[i] = 1;
        }
        else
        {
            num[i] = 0;
        }

        //cout << "INITIAL " << i << "  " << num[i] << endl;

        for(int j = 1; j <= min(6, i-1); j++)
        {
            num[i] += num[i-j];
            num[i] = num[i]%mod;

            //cout << num[i] << " " << j << " " << num[i-j] << endl;
        }

        //cout << i << " " << num[i] << endl;
    }

    cout << num[n];    
}

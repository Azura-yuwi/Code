//USACO Guide String Hashing

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll hsh[1000001];
const ll p = 9973;
const ll mod = 1e9 + 7;

ll compute(int a, int b, ll power)
{
    //cout << "COMPUTE " << a << " to " << b << hsh[b+1] << " " << hsh[a] << endl;
    return (hsh[b+1] - (hsh[a]*power)%mod + mod)%mod;
}

int main()
{
    int t;
    cin >> t;

    hsh[0] = 1;

    for(int i = 0; i < t; i++)
    {
        string s;

        cin >> s;
        int n = s.length();
        //cout << n << endl;

        for(int i = 1; i <= n; i++)
        {
            hsh[i] = (hsh[i-1]*p)%mod + (s[i-1]);
            hsh[i] = hsh[i]%mod;
        }

        int l1 = 0;
        int l2 = 0;
        int r1 = n-1;
        int r2 = n-1;

        int ans = 0;
        int copyn = n;
        ll power = p;

        while(l2 < r2)
        {
            //cout << l1 << " " << l2 << " " << compute(l1, l2, power) << " " << r1 << " " << r2 << " " << compute(r2, r1, power) << endl;
           // cout << s.substr(l1, l2+1) << " " << s.substr(r2, r1+1) << endl;

            if(compute(l1, l2, power) == compute(r2, r1, power))
            {
                copyn -= (2*(l2-l1+1));
                l1 = l2 + 1;
                r1 = r2 - 1;
                power = p;
                ans += 2;
            }
            else
            {
                power *= p;
                power %= mod;
            }

            l2++;
            r2--;
            //cout << copyn << endl;
            //cout << endl;
        }

        if(copyn > 0)
        {
            ans++;
        }

        cout << ans << endl;        
    }
}
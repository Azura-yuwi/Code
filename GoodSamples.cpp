#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,m; ll k; cin >> n >> m >> k;

    if(k < n)
    {
        cout << -1; return 0;
    }

    ll up = ((ll) m)*(m+1)/2 + (n-m)*(ll)m;

    if (k > up)
    {
        cout << -1; return 0;
    }

    ll add = k-n;
    ll num = n;
    int p = m-1;

    for(int i = 0; i < m; i++)
    {
        if(add >= i)
        {
            p++; p %= m;
            cout << (p+1) << " ";
            num--;
            add -= i;
        }
        else
        {
            break;
        }
    }

    //cout << "DEBUG " << (p+1) << " " << add << " " << num << endl;

    while(num > 0)
    {
        if(add >= m-1)
        {
            p++;
            add -= (m-1);
        }
        else
        {
            p += (m - add);
            add = 0;
        }

        p %= m;
        cout << (p+1) << " ";
        num--;
    }
}
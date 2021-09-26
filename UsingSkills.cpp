//GPL Problem G

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

ll val[200003];
int n;

ll skill(ll t)
{
    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += t/val[i];
    }

    return ans;
}

int main()
{
    ll k;
    cin >> n >> k;
    //cout << endl;

    k -= n;

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    ll left = 0; ll right = k*val[0];
    //cout << left << " " << right << endl;

    while(left < right)
    {
        ll mid = (left + right)/2;
        ll get = skill(mid);

        if(get >= k)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }

        //cout << left << " " << right << endl;
    }

    cout << left;
}
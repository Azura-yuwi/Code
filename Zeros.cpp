#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second

ll twos(ll a, ll b) // a < b;
{
    ll p = 2;
    ll ans = 0; 

    while(p <= b)
    {
        ll mult = b/p; //p*mult = greatest multiple of p <= b;

        if(a <= p*mult)
        {
            ans++;
            p *= 2;
        }
        else
        {
            return ans;
        }
    }

    return ans;
}

ll fives(ll a, ll b)
{
    ll p = 5;
    ll ans = 0; 

    while(p <= b)
    {
        ll mult = b/p; //p*mult = greatest multiple of p <= b;

        if(a <= p*mult)
        {
            ans++;
            p *= 5;
        }
        else
        {
            return ans;
        }
    }
    
    return ans;
}

int main()
{
    ll a,b; cin >> a >> b;
    //cout << twos(a,b) << " " << fives(a,b) << endl;
    cout << min(twos(a,b), fives(a,b)) << endl;
}


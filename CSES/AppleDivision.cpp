//CSES Intro Set;
//DP ish?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n;
    cin >> n;

    int val[n+1];
    vector<ll> sums;
    ll total = 0;

    sums.pb(0);

    for(int i = 1; i <= n; i++)
    {
        cin >> val[i];
        total += val[i];
        
        //cout << "AT " << i << " VAL " << val[i] << endl;

        for(int get = 0; get < pow(2, i-1); get++)
        {
            //cout << "ADD " << (sums[get] + val[i]) << endl;
            sums.pb(sums[get] + val[i]);
        }
    }

    ll dif = LLONG_MAX;

    for(ll i : sums)
    {
        dif = min(dif, abs(total - 2*i));
    }

    cout << dif;
}
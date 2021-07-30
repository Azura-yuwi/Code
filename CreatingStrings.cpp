//CSES Intro Set;
//Strings?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    vector<ll> perm[9];
    perm[1].pb(1);

    int n;
    cin >> n;

   // cout << ((ll)1/pow(10,1)) << endl;

    for(int i = 2; i <= n; i++)
    {
        for(ll get : perm[i-1])
        {
            ll power = 1;

            for(int j = 0; j < i; j++)
            {
                //cout << power << " " << get << " " << 10*(get/power)*power << " " << i*power << " " << get%power << endl;
                perm[i].pb(10*(get/power)*power + (i*power) + (get%power));
                power *= 10;
            }
        }
    }

    for(ll i : perm[n])
    {
        //cout << i << endl;
    }
}
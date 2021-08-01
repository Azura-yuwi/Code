//CSES Intro Set;
//Strings & sort of brute force

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    vector<ll> perm[9];
    perm[1].pb(1);

    string s;
    cin >> s;
    int n = s.length();

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

    set<string> strs;

    for(int i : perm[n])
    {
        string make = "";

        while(i > 0)
        {
            make = s[i%10 - 1] + make;
            i /= 10;
        }

        strs.insert(make);
    }

    cout << strs.size() << endl;

    for(string i : strs)
    {
        cout << i << endl;
    }
}
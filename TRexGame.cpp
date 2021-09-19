//GPL Problem 5

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
    int n; cin >> n;

    int val[n];
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<pair<int, int>> ob;
    ob.pb(mp(0,0));

    int at = 0;

    while(at < n)
    {
        int prev = at; at++;

        while(at < n && val[at] == val[prev])
        {
            at++;
        }

        ob.pb(mp(val[prev], at - prev));
    }

    ll d[ob.size()]; pair<ll, ll> j[ob.size()];

    d[0] = 0; j[0] = mp(0,1);

    for(int i = 1; i < ob.size(); i++)
    {
        d[i] = -1; j[i] = mp(-1,-1);

        if(ob[i].first != 1)
        {
            d[i] = max(d[i-1], j[i-1].first) + 5*ob[i].second;
        }

        if(ob[i].first != 0)
        {
            int add = pow(2, ob[i].second) - 1;

            if(d[i-1] != -1) 
            {
                j[i] = mp(d[i-1] + 2*add, add+1);
            }

            if(j[i-1].first != -1 && j[i].first <= j[i-1].first + j[i-1].second*2*add)
            {
                j[i].first = j[i-1].first + j[i-1].second*2*add;
                j[i].second = j[i-1].second*(add+1);
            }
        }
    }

    cout << max(j[ob.size() - 1].first, d[ob.size() -1]);
}
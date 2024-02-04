//CSES Sorting and Searching

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    
    ll val[n];
    ll total = 0;
    int r = n;
    int l = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
        total += val[i];
    }

    sort(val, val+n);

    vector<pair<ll,int>> cmprs;
    cmprs.pb(mp(0,1));

    for(int i = 0; i < n; i++)
    {
        if(cmprs[cmprs.size()-1].first == val[i])
        {
            cmprs[cmprs.size()-1].second++;
        }
        else
        {
            cmprs.pb(mp(val[i], 1));
        }
    }

    for(int i = 1; i < cmprs.size(); i++)
    {
        //cout << total << " " << l << " " << r << endl;

        if(l < r)
        {
            total -= (r-l)*(cmprs[i].first-cmprs[i-1].first);
            r -= cmprs[i].second;
            l += cmprs[i].second;
        }
    }

    cout << total;    
}
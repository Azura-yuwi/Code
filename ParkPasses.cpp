#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,m; cin >> n >> m;
   // vector<pair<int, pair<int, ll>>> packs;
    vector<pair<int,ll>> packs[m+1];

    for(int i = 0; i < n; i++)
    {
        int a,b; ll c; cin >> a >> b >> c;

        packs[b].pb(mp(a,c));
    }

    if(packs[m].size() == 0)
    {
        cout << -1; return 0;
    }

    unordered_map<int,ll> carry;
    carry[0] = 0;
    ll ans = LLONG_MAX;

    for(int d = m; d > 0; d--)
    {
        for(pair<int,ll> get : packs[d])
        {
            unordered_map<int,ll> fill;

            for(auto toAdd : carry)
            {
                int num = toAdd.f + get.f; //ticket number
                ll cost = toAdd.s + get.s;

                if(num >= m)
                {
                    ans = min(ans, cost);
                }
                else
                {
                    if(fill.find(num) == fill.end())
                    {
                        fill[num] = cost;
                    }
                    else
                    {
                        fill[num] = min(fill[num], cost);
                    }
                }

                if(toAdd.f >= (m+1)-d)
                {
                    if(fill.find(toAdd.f) == fill.end())
                    {
                        fill[toAdd.f] = toAdd.s;
                    }
                    else
                    {
                        fill[toAdd.f] = min(fill[toAdd.f], toAdd.s);
                    }
                }
            }

            carry = fill;
        }
    }

    if(ans == LLONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }

    //cout << ans;
}
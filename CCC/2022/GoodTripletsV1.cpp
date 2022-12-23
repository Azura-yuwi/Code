#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,c; cin >> n >> c;
    ll p[c];
    ll cul[c+1];

    for(int i = 0; i < c; i++)
    {
        p[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        p[a]++;
    }

    cul[0] = 0;

    for(int i = 0; i < c; i++)
    {
        cul[i+1] = cul[i] + p[i];
    }

    ll ans = 0;
    int mid = c/2;

    vector<pair<int,ll>> p1;
    vector<pair<int,ll>> p2;

    for(int i = 0; i < mid; i++)
    {
        if(p[i] > 0)
        {
            p1.pb(mp(i, p[i]));
        }
    }

    for(int i = mid; i < c; i++)
    {
        if(p[i] > 0)
        {
            p2.pb(mp(i, (ll)p[i]));
        }
    }

    if(c%2 == 0)
    {
        for(int i = 0; i < p1.size(); i++)
        {
            for(int j = i + 1; j < p1.size(); j++)
            {
                ans += p1[i].s*p1[j].s*(cul[p1[j].f+mid] - cul[p1[i].f+mid+1]);
            }   
        }

        for(int i = 0; i < p2.size(); i++)
        {
            for(int j = i + 1; j < p2.size(); j++)
            {
                ans += p2[i].s*p2[j].s*(cul[p2[j].f-mid] - cul[p2[i].f-mid+1]);
            }   
        }
    }
    else
    {
        for(int i = 0; i < p1.size(); i++)
        {
            for(int j = i + 1; j < p1.size(); j++)
            {
                ans += p1[i].s*p1[j].s*(cul[p1[j].f+mid+1] - cul[p1[i].f+mid+1]);
            }   
        }

        for(int i = 0; i < p2.size(); i++)
        {
            for(int j = i + 1; j < p2.size(); j++)
            {
                ans += p2[i].s*p2[j].s*(cul[p2[j].f-mid] - cul[p2[i].f-mid]);
            }   
        }
    }

    cout << ans;
}
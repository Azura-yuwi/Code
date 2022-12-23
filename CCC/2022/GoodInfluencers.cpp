#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n; cin >> n;
    vector<int> adj[n];
    vector<int> nlit;
    bool y[n];

    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
        y[i] = false;
    }

    y[0] = false; string s; cin >> s;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'Y')
        {
            y[i] = true;
            nlit.pb(i);
        }
    }

    int cost[n];
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int cul[n+1];
    cul[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cul[i] = cul[i-1] + cost[i-1];
    }

    int ans = 0;
    
    for(int i = 0; i <= nlit.size(); i++)
    {
        if(i == 0)
        {
            ans += cul[nlit[i]+1] - cost[0];
        }
        else if(i == nlit.size())
        {
            ans += cul[n] - cul[nlit[i-1]] - cost[n-1];
        }
        else
        {
            int toAdd = INT_MAX;

            for(int k = nlit[i-1] + 1; k < nlit[i]; k++)
            {
                int lcost = cul[k] - cul[nlit[i-1]+1]; 
                int rcost = cul[nlit[i]+1] - cul[k+1];
                toAdd = min(toAdd, lcost + rcost);
            }

            if(toAdd = INT_MAX)
            {
                toAdd = 0;
            }

            ans += toAdd;
        }
    }

    cout << ans;    
}
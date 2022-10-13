#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int n,m;
vector<pair<int,ll>> adj[200005];
ll m1[200005];
ll m2[200005];
ll m3[200005];
ll rt[200005];

void dfs(int at, int p)
{
    m1[at] = 0;
    m2[at] = 0;
    m3[at] = 0;

    for(auto to : adj[at])
    {
        int i; ll c; tie(i,c) = to;

        if(i != p)
        {
            dfs(i, at); ll upd = m1[i] + c;

            if(upd >= m1[at])
            {
                m3[at] = m2[at]; m2[at] = m1[at]; m1[at] = upd;
            }
            else if(upd >= m2[at])
            {
                m3[at] = m2[at]; m2[at] = upd;
            }
            else if(upd > m3[at])
            {
                m3[at] = upd;
            }
        }
    }
}

void dfs2(int at, int p)
{
    rt[at] = m3[at] + 2*m2[at] + m1[at];

    for(int i = 0; i < adj[at].size(); i++)
    {
        int to; ll c; tie(to,c) = adj[at][i];

        if(to != p)
        {
            ll pUp = m1[at];
            if(m1[at] == m1[to] + c) pUp = m2[at];
            pUp += c;

            if(m1[to] <= pUp)
            {
                m3[to] = m2[to]; m2[to] = m1[to]; m1[to] = pUp;
            }
            else if(m2[to] <= pUp)
            {
                m3[to] = m2[to]; m2[to] = pUp;
            }
            else if(m3[to] < pUp)
            {
                m3[to] = pUp;
            }

            dfs2(to, at);
        }
    }

}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n-1; i++)
    {
        int a,b; ll t; cin >> a >> b >> t; a--;b--;
        adj[a].pb(mp(b,t));
        adj[b].pb(mp(a,t));
    } 

    dfs(0, -1);
    dfs2(0, -1);
    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, rt[i]);
        //cout << rt[i] << endl;
    }
    
    cout << ans;
}
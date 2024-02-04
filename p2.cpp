#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n,m; cin >> n >> m;
    vector<pair<int,ll>> adj[n];
    vector<int> topord;
    int indeg[n];
    int dist[n];
    pair<int,ll> p[n];
    vector<int> lex[n];
    int lexval[n];
    ll ans[n];

    for(int i = 0; i < n; i++)
    {
        indeg[i] = 0; dist[i] = 0; p[i] = mp(i,0);  lexval[i] = 0; ans[i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b; ll c; cin >> a >> b >> c; a--; b--;
        adj[a].pb(mp(b,c));
        indeg[b]++;
    }

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int get = q.front(); q.pop();
        topord.pb(get);

        for(auto to : adj[get])
        {
            int node; ll val; tie(node, val) = to;
            indeg[node]--;

            if(indeg[node] == 0)
            {
                q.push(node);
            }
        }
    }

    for(int i = n-1; i >= 0; i--)
    {
        int get = topord[i];
        for(auto to : adj[get])
        {
            int node; ll val; tie(node, val) = to;

            if(dist[node] + 1 > dist[get])
            {
                dist[get] = dist[node]+1; p[get] = mp(node, val);
            }
            else if(dist[node] + 1 == dist[get])
            {
                if(val < p[get].s || (val == p[get].s && lexval[node] < lexval[p[get].f]))
                {
                    dist[get] = dist[node]+1; p[get] = mp(node, val);
                }
            }
        }

        lex[dist[get]].pb(get); lexval[get] = (int)(lex[dist[get]].size() - 1);

        for(int j = lex[dist[get]].size() - 2; j >= 0; j--)
        {
            int a = lex[dist[get]][j+1];
            int b = lex[dist[get]][j];

            if(p[a].s < p[b].s || (p[a].s == p[b].s && lexval[p[a].f] < lexval[p[b].f]))
            {
                lexval[a]--;
                lexval[b]++;
                lex[dist[get]][j+1] = b;
                lex[dist[get]][j] = a;
            }
            else
            {
                break;
            }
        }
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(p[topord[i]].f != topord[i])
        {
            ans[topord[i]] = p[topord[i]].s + ans[p[topord[i]].f];
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << dist[i] << " " << ans[i] << endl;
    }
}
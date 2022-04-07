#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define T pair<int, pair<int,int>>
#define f first
#define s second

vector<pair<int,int>> edges;
vector<int> adj[100001];
vector<pair<char, pair<int,int>>> queries;
bool ans[100001];
bool active[100001];
bool visit[100001];
int head[100001];

void dfs(int a, bool lit)
{
    for(int to : adj[a])
    {
        if(!visit[to])
        {
            visit[to] = true;
            active[to] = active[to]|lit;
            dfs(to, active);
        }
    }
}

int find(int a)
{
    if(head[a] < 0)
    {
        return a;
    }

    head[a] = find(head[a]);
    return head[a];
}

bool unite(int a, int b)
{
    a = find(a); b = find(b);

    if(a == b)
    {
        return false;
    }

    if(active[a] && !active[b])
    {
        active[b] = true;
        dfs(b, true);
    }
    
    if(!active[head[a]] && active[head[b]])
    {
        active[a] = true;
        dfs(a, true);
    }

    if(head[a] > head[b]) {swap(a,b);}
    head[a] += head[b]; head[b] = a; 

    return true;
}


int main()
{
    int n,q; cin >> n >> q;

    vector<bool> activeEdges;
    
    for(int i = 0; i < n; i++)
    {
        ans[i] = -1;
        active[i] = true;
        head[i] = -1;
        visit[i] = false;
    }

    for(int i = 0; i < q; i++)
    {
        int c; cin >> c;
        
        if(c == 'A')
        {
            int a,b; cin >> a >> b; a--; b--;
            queries.pb(mp(c, mp(a,b)));
            edges.pb(mp(a,b));
            activeEdges.pb(true);
        }
        else if(c == 'D')
        {
            int a; cin >> a; a--; queries.pb(mp(c,mp(a,0)));
            active[a] = false;
        }
        else if(c == 'R')
        {
            int a; cin >> a; a--; queries.pb(mp(c, mp(a,0)));
            activeEdges[a] = false;
        }
    }

    for(int i = 0; i < edges.size(); i++)
    {
        if(activeEdges[i])
        {
            adj[edges[i].f].pb(edges[i].s);
            adj[edges[i].s].pb(edges[i].f);
        }

        unite(edges[i].f, edges[i].s);
    }

    for(int i = 0; i < n; i++)
    {
        if(active[i])
        {
            ans[i] = q;
        }
    }


    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
        
    }

}
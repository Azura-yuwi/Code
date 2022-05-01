#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[200000];
int dist[200000];
int n;

void dfs(int p)
{
    for(int t : adj[p])
    {
        if(dist[t] != n+1)
        {
            dist[t] = dist[p] + 1;
            dfs(t);
        }
    }
}

int main()
{
    int w,d; cin >> n >> w >> d;

    for(int i = 0; i < w; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj[b].pb(a);
    }

    int perm[n];
    int pos[n];

    for(int i = 0; i < n; i++)
    {
        dist[i] = n+1;
        cin >> perm[i]; perm[i]--;
        pos[perm[i]] = i;
    }

    dist[n-1] = 0;
    dfs(n-1);

    stack<pair<int,int>> stk;
    stk.push(mp(n-1, pos[n-1]));

    for(int i = pos[n-1]-1; i >= 0; i--)
    {
        int d = pos[]
    }

}
//USACO Guide Binary Jumping
//USACO Plat 2015 Dec

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int maxn = 200002;
const int maxd = 22;
int lay[maxn][maxd];
vector<pair<int,int>> adj[maxn];
int dep[maxn];
int up[maxn];
int ans[maxn];
int sub[maxn];

void dfs(int at, int p)
{
    for(pair<int,int> get : adj[at])
    {
        if(get.f == p)
        {
            continue;
        }

        dep[get.f] = dep[at] + 1;
        lay[get.f][0] = at;

        dfs(get.f, at);
    }
}

int jump(int a, int num)
{
    int at = 0;

    while(num > 0)
    {
        if(num%2 == 1)
        {
            a = lay[a][at];
        }

        at++;
        num /= 2;
    }

    return a;
}

void dfs2(int at, int p)
{
    for(pair<int,int> get: adj[at])
    {
        if(get.f == p)
        {
            continue;
        }

        dfs2(get.f, at);
        ans[at] += (ans[get.f] - up[get.f]);
    }

    ans[at] -= up[at];
}

void lca(int a, int b)
{
    if(dep[a] > dep[b])
    {
        swap(a,b);
    }

    b = jump(b, dep[b] - dep[a]);

    if(a == b)
    {
        up[a]++; 
        return;
    }

    for(int d = maxd - 1; d >= 0; d--)
    {
        if(lay[b][d] != lay[a][d])
        {
            b = lay[b][d];
            a = lay[a][d];
        }
    }

    up[lay[a][0]]++;
}

int main()
{
    ifstream fin("maxflow.in");
   ofstream fout("maxflow.out");

    int n,k; fin >> n >> k;
    
    for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxd; j++)
        {
            lay[i][j] = 0;
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        int a,b; fin >> a >> b;
        adj[a].pb(mp(b,i));
        adj[b].pb(mp(a,i));
        up[i+2] = 0;
    }

    up[1] = 0; dep[1] = 0;
    dfs(1, 0);

    for(int d = 1; d < maxd; d++)
    {
        for(int i = 1; i <= n; i++)
        {
            lay[i][d] = lay[lay[i][d-1]][d-1];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        ans[i] = 0;
    }

    for(int i = 0; i < k; i++)
    {
        int a,b; fin >> a >> b;
        ans[a]++; ans[b]++;
        lca(a,b);
    }
    dfs2(1,0);
    int mx = 0;

    for(int i = 1; i <= n; i++)
    {
        mx = max(mx, ans[i]);
    }

    fout << mx << endl;
}

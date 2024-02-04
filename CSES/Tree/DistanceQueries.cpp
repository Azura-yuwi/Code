//USACO Guide Binary Jumping
//CSES Tree Algorithms

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
int dep[maxn];
vector<int> adj[maxn];

void dfs(int at, int p)
{
    for(int get : adj[at])
    {
        if(get == p)
        {
            continue;
        }

        lay[get][0] = at;
        dep[get] = dep[at] + 1;
        dfs(get, at);
    }
}

int jump(int at, int num)
{
    int d = 0;

    while(num > 0)
    {
        if(num%2 == 1)
        {
            at = lay[at][d];
        }

        d++; num /= 2;
    }

    return at;
}

int lca(int a, int b)
{
    if(dep[a] > dep[b])
    {
        swap(a,b);
    }

    b = jump(b, dep[b] - dep[a]);

    if(a == b)
    {
        return a;
    }

    for(int j = maxd - 1; j >= 0; j--)
    {
        if(lay[a][j] != lay[b][j])
        {
            b = lay[b][j]; a = lay[a][j];
        }
    }
    
    return lay[a][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,q; cin >> n >> q;
    
    for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxd; j++)
        {
            lay[i][j] = 0;
        }
    }

    for(int i = 2; i <= n; i++)
    {
        int a,b; cin >> a >> b;
        adj[b].pb(a); 
        adj[a].pb(b);
    }

    dep[1] = 0;
    dfs(1,0);

    for(int j = 1; j < maxd; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            lay[i][j] = lay[lay[i][j-1]][j-1];
        }
    }

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        int p = lca(a,b);

        //cout << a << " " << b << " " << p << endl;
        cout << dep[a] + dep[b] - 2*dep[p] << endl;
    }
}
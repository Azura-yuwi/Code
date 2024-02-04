//USACO Guide Binary Jumping
//USACO Plat 2015 Dec

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int maxn = 50005;
const int maxd = 16;
int lay[maxn][maxd];
vector<pair<int,int>> adj[maxn];
int dep[maxn];
pair<int,int> up[maxn];
multiset<int> dub;
int ans[maxn];
int nxt[maxn];

void make(int x, int p)
{
    for(auto get : adj[x])
    {
        if(get.f == p)
        {
            continue;
        }

        dep[get.f] = dep[x] + 1;
        up[get.f] = mp(x, get.s);
        nxt[get.f] = get.f;
        lay[get.f][0] = x;
        make(get.f, x);
    }
}

int jump(int x, int n)
{
    int at = 0;

    while(n > 0)
    {
        if(n%2 == 1)
        {
            x = lay[x][at];
        }

        at++; n /= 2;
    }

    return x;
}

void pushup(int a, int lc, int w)
{
    //cout << "at " << a << endl;
    a = nxt[a];

    while(dep[a] > dep[lc])
    {
        if(ans[up[a].s] == -1 || ans[up[a].s] > w)
        {
            ans[up[a].s] = w;
        }

        nxt[a] = nxt[lc]; //sort of dsu ?
        a = nxt[up[a].f];
    }
}

void lca(int a, int b, int w)
{
    if(dep[a] > dep[b])
    {
        swap(a,b);
    }

    int nb = jump(b, dep[b] - dep[a]);

    if(a == nb)
    {
        pushup(b, a, w);
    }
    else
    {
        int na = a;

        for(int d = maxd - 1; d >= 0; d--)
        {
            if(lay[na][d] != lay[nb][d])
            {
                na = lay[na][d]; nb = lay[nb][d];
            }
        }

        pushup(a, lay[na][0], w);
        pushup(b, lay[na][0], w);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ifstream fin("disrupt.in");
    ofstream fout("disrupt.out");

    int n,m; fin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < maxd; j++)
        {
            lay[i][j] = 0;
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        int p,q; fin >> p >> q;
        adj[p].pb(mp(q,i));
        adj[q].pb(mp(p,i));
    }
    
    dep[0] = -1; dep[1] = 0; nxt[1] = 1;
    make(1,0);

    for(int d = 1; d < maxd; d++)
    {
        for(int i = 1; i <= n; i++)
        {
            lay[i][d] = lay[lay[i][d-1]][d-1];
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        ans[i] = -1;
    }

    vector<pair<int, pair<int,int>>> bridges;

    for(int i = 0; i < m; i++)
    {
        int p,q,r; fin >> p >> q >> r;
        bridges.pb(mp(r, mp(p,q)));
    }

    sort(bridges.begin(), bridges.end());

    for(int i = 0; i < m; i++)
    {
        int p,q,r; r = bridges[i].f; tie(p,q) = bridges[i].s;
        lca(p,q,r);
    }

    for(int i = 0; i < n-1; i++)
    {
        fout << ans[i] << endl;
    }
}
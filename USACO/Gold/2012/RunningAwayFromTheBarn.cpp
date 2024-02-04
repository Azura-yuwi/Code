//USACO Guide Binary Jumping
//USACO Old Gold 2012 Dec 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int maxn = 200005;
const int maxd = 22;
pair<int,ll> lay[maxn][maxd];
vector<pair<int, ll>> adj[maxn];
pair<int,ll> up[maxn];
int num[maxn];
int sum[maxn];
ll l;

void fill(int x, int p)
{
    for(auto get : adj[x])
    {
        if(get.f == p)
        {
            continue;
        }

        up[get.f] = mp(x, get.s);
        lay[get.f][0] = mp(x, get.s);

        fill(get.f, x);
    }
}

void mark(int x)
{
    ll tot = 0;
    num[x]++;

    for(int d = maxd - 1; d >= 0; d--)
    {
        if(lay[x][d].s + tot <= l)
        {
            tot += lay[x][d].s;
            x = lay[x][d].f;
        }
    }

    num[lay[x][0].f]--;

    //cout << "marked " << x << " " << lay[x][0].f << endl;
}

void dfs(int x, int p)
{
    sum[x] = num[x];

    for(auto get : adj[x])
    {
        if(get.f == p)
        {
            continue;
        }

        dfs(get.f, x);
        sum[x] += sum[get.f];
    }
}

int main()
{
    ifstream fin("runaway.in");
    ofstream fout("runaway.out");

    int n; fin >> n >> l;

    for(int i = 2; i <= n; i++)
    {
        int p; ll li; fin >> p >> li;
        adj[i].pb(mp(p,li));
        adj[p].pb(mp(i,li));
    }
    
    for(int i = 0; i <= n; i++)
    {
        num[i] = 0;

        for(int j = 0; j < maxd; j++)
        {
            lay[i][j] = mp(0,0);
        }
    }

    fill(1,0);

    for(int d = 1; d < maxd; d++)
    {
        for(int i = 1; i <= n; i++)
        {
            lay[i][d] = mp(lay[lay[i][d-1].f][d-1].f, lay[lay[i][d-1].f][d-1].s + lay[i][d-1].s);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        mark(i);
    }

    dfs(1,0);

    for(int i = 1; i <= n; i++)
    {
        fout << sum[i] << endl;
    }

}
//dp on tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

const ll mod = 1e9+7;

int n;
vector<int> adj[100000];
ll w[100000]; ll b[100000];

void dfs(int at, int p)
{
    //bool leaf = true;

    w[at] = 1; b[at] = 1;

    for(int to : adj[at])
    {
        if(to != p)
        {
            //leaf = false;
            dfs(to, at);
            w[at] *= ((w[to] + b[to])%mod);
            b[at] *= w[to];

            w[at] %= mod; b[at] %= mod;
        }
    }

}

int main()
{
    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int a,b; cin >> a >> b; a--;b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(0,0);
    cout << ((w[0]+b[0])%mod) << endl;
}
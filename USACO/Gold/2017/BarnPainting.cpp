//USACO Gold 2017 December
//Tree DP

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int nMax = 100001;
ll mod = 1e9 + 7;
int n;
vector<int> adj[100001];
ll color[100001][3];

void dfs(int node, int p)
{
    for(int to : adj[node])
    {
        if(to != p)
        {
            dfs(to, node);

            for(int i = 0; i < 3; i++)
            {
               color[node][i] *= ((color[to][(i+1)%3] + color[to][(i+2)%3])%mod); 
               color[node][i] %= mod;
            }
        }
    }
}

int main()
{
    ofstream fout ("barnpainting.out");
    ifstream fin ("barnpainting.in");

    int k; fin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        color[i][0] = 1;
        color[i][1] = 1;
        color[i][2] = 1;
    }


    for(int i = 1; i < n; i++)
    {
        int a,b; fin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }    

    for(int i = 0; i < k; i++)
    {
        int b, c; fin >> b >> c; b--;
        color[b][(c+1)%3] = 0;
        color[b][(c+2)%3] = 0;
    }
    
    dfs(0, 0);
    fout << (color[0][0] + color[0][1] + color[0][2])%mod;
}

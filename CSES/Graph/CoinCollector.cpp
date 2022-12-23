//CSES Graph
//USACO Strongly Connected Components 
//Kosaraju's Algorithm + DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[100005];
vector<int> rev[100005];
vector<int> ord;
bool visit[100005];
int id[100005];
int val[100005];
ll dp[100005];
vector<int> compto[100005];
int comp; //number of components
int n;

void dfs(int x, int round, int num)
{
    visit[x] = true;
    vector<int> &ad = (round == 0) ? adj[x] : rev[x];

    for(int to : ad)
    {
        if(!visit[to])
        {
            dfs(to, round, num);
        }
        else if(round == 1 && id[to] != 0 && id[to] != num)
        { 
            compto[id[to]].pb(num); //component id[to] can travel to component num;
        }
    }

    ord.pb(x);
    
    if(round == 1)
    {
        id[x] = num;
        dp[num] += (ll)val[x];
    }
}

void clear()
{
    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
}

void kosaraju()
{
    clear();

    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            dfs(i, 0, 0);
        }
    }

    clear();

    comp = 0;

    for(int i = n-1; i >= 0; i--)
    {
        if(!visit[ord[i]])
        {
            comp++;
            dfs(ord[i], 1, comp);
        }
    }
}

void calc(int src)
{
    ll add = 0;

    for(int to : compto[src])
    {
        if(!visit[to])
        {
            visit[to] = true;
            calc(to);
        }

        add = max(add, dp[to]);
    }

    dp[src] += add;

    return;
}

int main()
{
    int m; cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
        dp[i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        rev[b].pb(a);
    }

    kosaraju();
    clear();

    ll coin = 0;
    
    for(int i = 1; i <= comp; i++)
    {
        //cout << "OG " << i << " " << dp[i] << endl; 

        if(!visit[i])
        {
            calc(i);
        }

        coin = max(coin, dp[i]);
    }

    cout << coin;

}

//with DP, it's technically a tree after you find all components. 
//So any graph/tree trasversal stuff should work. 
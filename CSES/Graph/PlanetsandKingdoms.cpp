//CSES Graph
//USACO Strongly Connected Components
//Kosaraju's Algorith 

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
    }

    ord.pb(x);
    
    if(round == 1)
    {
        id[x] = num;
    }
}

void clear(int n)
{
    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
}

int main()
{
    int n,m; cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        adj[a-1].pb(b-1);
        rev[b-1].pb(a-1);
    }

    clear(n);

    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            dfs(i, 0, 0);
        }
    }

    clear(n);

    int comp = 0;

    for(int i = n-1; i >= 0; i--)
    {
        if(!visit[ord[i]])
        {
            comp++;
            dfs(ord[i], 1, comp);
        }
    }

    cout << comp << endl;

    for(int i = 0; i < n; i++)
    {
        cout << id[i] << " ";
    }

}
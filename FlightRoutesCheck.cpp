//CSES Graph
//Strongly Connected Components
// Kosaraju's Algorith (but cut short a bit)

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

int main()
{
    int n,m; cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        adj[a-1].pb(b-1);
        rev[b-1].pb(a-1);
    }

    dfs(0, 0, 0);

    for(int i = 1; i < n; i++)
    {
        if(!visit[i])
        {
            cout << "NO" << endl;
            cout << "1 " << (i+1) << endl;
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    dfs(ord[n-1], 1, 1);

    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            cout << "NO" << endl;
            cout << (i+1) << " " << (ord[n-1]+1) << endl;
            return 0;
        }
    }

    cout << "YES" << endl;


}
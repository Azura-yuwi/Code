//USACO Gold 2020 Open
//Graph -- DSU?

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int root[200000];
vector<int> point[200000];
vector<int> adj[20000];
queue<int> q;

int find(int a)
{
    if(root[a] < 0)
    {
        return a;
    }

    root[a] = find(root[a]);
    return root[a];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a > b)
    {
        swap(a,b);
    }

   /* if(point[a].size() < point[b].size())
    {
        swap(a,b);
    }

    for(int i : point[b])
    {
        point[a].pb(i);
        root[i] = a;
    }*/

    root[b] = a;

    adj[a].insert(adj[a].end(), adj[b].begin(), adj[b].end());
    adj[b].clear();
    
    if(adj[a].size() > 1)
    {
        q.push(a);
    }    
}

int main()
{
    ifstream fin("fcolor.in");
    ofstream fout("fcolor.out");

    int n,m; fin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b; fin >> a >> b; a--; b--;
        adj[a].pb(b); //b admires cow a
    }

    int colors[n];

    for(int i = 0; i < n; i++)
    {
        root[i] = -1;
        //point[i].pb(i); 
        colors[i] = 0;

        if(adj[i].size() > 1)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int get = q.front();

        if(adj[get].size() <= 1)
        {
            q.pop();
            continue;
        }

        int to = adj[get].back(); adj[get].pop_back();

        if(find(to) != find(adj[get].back()))
        {  
            merge(to, adj[get].back());
            //cout << get << " merged " << to << " " << adj[get].back() << endl;
        }
    }

    int on = 1;

    for(int i = 0; i < n; i++)
    {
        if(colors[find(i)] == 0)
        {
            colors[find(i)] = on; on++;
        }

        fout << colors[find(i)] << endl;
    }
}
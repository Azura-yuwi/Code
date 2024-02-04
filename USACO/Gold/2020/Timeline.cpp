////USACO Gold 2020 February
//Topological Sort

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    ifstream fin("timeline.in");
    ofstream fout("timeline.out");
    
    int n,m,c; fin >> n >> m >> c;
    int day[n];
    vector<pair<int,int>> adj[n];
    int in[n];

    for(int i = 0; i < n; i++)
    {
        fin >> day[i];
        in[i] = 0;
    }

    for(int i = 0; i < c; i++)
    {
        int a, b, x; fin >> a >> b >> x; a--; b--;
        adj[a].pb(mp(b,x));
        in[b]++;
    }

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int get = q.front(); q.pop();
        
        for(pair<int,int> to : adj[get])
        {
            int node, val; tie(node, val) = to;
            day[node] = max(day[node], day[get] + val);
            in[node]--;
            if(in[node] == 0) {q.push(node);}
        }
    }

    for(int i = 0; i < n; i++)
    {
        fout << day[i] << endl;
    }
}
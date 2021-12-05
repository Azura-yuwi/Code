//USACO Gold 2017 December
//BFS + 

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    ofstream fout ("piepie.out");
    ifstream fin ("piepie.in");

    int n,d; fin >> n >> d;
    pair<int,int> p[2*n];
    vector<int> adj[2*n];
    int dist[2*n];
    queue<int> q;

    for(int i = 0; i < 2*n; i++)
    {
        dist[i] = -1;
        int a,b; fin >> a >> b;
        p[i] = mp(a,b);
        
        if(a == 0 && i >= n)
        {
            q.push(i);
            dist[i] = 1;
        }
        else if (b == 0 && i < n)
        {
            q.push(i);
            dist[i] = 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = n; j < 2*n; j++)
        {
            if(p[i].f >= p[j].f && p[i].f <= p[j].f + d)
            {
                adj[i].pb(j);
            }

            if(p[j].s >= p[i].s && p[j].s <= p[i].s + d)
            {
                adj[j].pb(i);
            }
        }
    }

    while(!q.empty())
    {
        int get = q.front(); q.pop();
        
        for(int to : adj[get])
        {
            if(dist[to] == -1)
            {
                dist[to] = dist[get]+1;
                q.push(to);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        fout << dist[i] << endl;
    }

}
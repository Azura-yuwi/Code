//CSES Graph
//Shortest Path--Dijkstra
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<pair<int,int>> adj[100003]; //node, cost
int minl[100003];
int maxl[100003];
int num[100003];
ll dist[100003];
bool visit[100003];
int mod = 1000000007;

void dijkstra(int src)
{
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src] = 0;
    minl[src] = 0;
    maxl[src] = 0;
    num[src] = 1;
    pq.push(mp(0,src));

    while(!pq.empty())
    {
        ll cdist; int node; tie(cdist, node) = pq.top();
        pq.pop();

        if(visit[node])
        {
            continue;
        }

        visit[node] = true;

        for(pair<int,int> to : adj[node])
        {
            if(to.second + cdist < dist[to.first])
            {
                minl[to.first] = minl[node] + 1;
                maxl[to.first] = maxl[node] + 1;
                num[to.first] = num[node];
                dist[to.first] = to.second + dist[node];
                pq.push(mp(dist[to.first], to.first));
            }
            else if(cdist + to.second == dist[to.first])
            {
                minl[to.first] = min(minl[to.first], minl[node] + 1);
                maxl[to.first] = max(maxl[to.first], maxl[node] + 1);
                num[to.first] = (num[to.first] + num[node])%mod;
                pq.push(mp(dist[to.first], to.first));
            }
        }
    }
}


int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        minl[i] = 100005;
        maxl[i] = -1;
        num[i] = 0;
        dist[i] = LLONG_MAX;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;

        adj[a-1].pb(mp(b-1,c));
    }

    dijkstra(0);

    cout << dist[n-1] << " " << num[n-1] << " " << minl[n-1] << " " << maxl[n-1] << endl;

}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using T = pair<ll, pair<int,int>>;
#define pb push_back

vector<pair<int, int>> graph[100000];
ll dist[100000];
ll half[100000];
int n;

struct Sort 
{
    bool operator() (T const& p1, T const& p2)
    {
        if(p1.first == p2.first)
        {
            return p1.second.first > p2.second.first;
        }

        return p1.first > p2.first;
    }
};

void dijkstra(int src)
{
    for(int i = 0; i < n; i++)
    {
        dist[i] = LLONG_MAX;
        half[i] = LLONG_MAX;
    }
    priority_queue<T, vector<T>, Sort> pq;

    dist[src] = 0;
    half[src] = 0;

    pq.push({0, {0, src}});

    while(pq.size())
    {
        ll cdist; pair<int,int> point;
        tie(cdist, point) = pq.top(); pq.pop();
        int type; int node;
        tie(type, node) = point;
        
        //cout << node << " " <<  type  << " " << cdist <<endl;

        if(type == 0)
        {
            if(cdist != dist[node]) continue;

            for(pair<int, int> i : graph[node])
            {
                if(cdist + i.second < dist[i.first])
                {
                    pq.push({dist[i.first] = cdist + i.second, {0, i.first}});
                }

                if(cdist + i.second/2 < half[i.first])
                {
                    pq.push({half[i.first] = cdist + i.second/2, {1, i.first}});
                }
            }
        }
        else
        {
            if(cdist != half[node]) continue;

            for(pair<int, int> i : graph[node])
            {
                if(cdist + i.second < half[i.first])
                {
                    pq.push({half[i.first] = cdist + i.second, {1, i.first}});
                }
            }
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a-1].pb({b-1,c});
    }

    dijkstra(0);
    cout << half[n-1];
}
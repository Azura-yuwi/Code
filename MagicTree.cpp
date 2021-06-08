#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back


int n,m,k;
ll INF = LONG_LONG_MAX;
ll val[100001] = {0};
int day[100001] = {0};
vector<int> child[100001];
map<int, ll> lists[100001];

void update(int src)
{
    for (int kid : child[src])
    {
        update(kid);
        for(int )
        
    }

}


int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;

        child[p-1].pb(i);
    }

    for(int i = 0; i < m; i++)
    {
        int v,d,w;
        cin >> v >> d >> w;
        day[v-1] = d;
        val[v-1] = w;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<pair<int,int>> adj[200000];
vector<pair<int,int>> costs;
int walks[200000];
stack<int> path;
unordered_set<int> visited;
bool found;

void dfs(int src, int p, int des)
{
   //cout << "at " << src << endl;

    if(src == des)
    {
        found = true;
        return;
    }

    for(pair<int,int> get : adj[src])
    {
        if(get.f != p)
        {
            //cout << "to " << get.f << endl;
            path.push(get.s);
            dfs(get.f, src, des);

            if(found)
            {
                return;
            }

            path.pop();
        }
    }
}

int main()
{
    int n; cin >> n;

    for(int i = 0; i < n-1; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        int c1,c2; cin >> c1 >> c2;
        adj[a].pb(mp(b,i));
        adj[b].pb(mp(a,i));
        costs.pb(mp(c1, c2));
        walks[i] = 0;
    }

    for(int i = 0; i < n-1; i++)
    {
        found = false;
        dfs(i, i, i+1);

        //cout << "path for i = " << i << " ";

        while(!path.empty())
        {
           // cout << path.top() << " ";
            walks[path.top()]++;
            path.pop();
        }

       // cout << endl;
    }

    ll total = 0;

    for(int i = 0; i < n-1; i++)
    {
        total += min(costs[i].s, costs[i].f*walks[i]);
    }

    cout << total << endl;


}
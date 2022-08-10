#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

vector<int> root;


int find(int src)
{
    if(root[src] < 0) { return src;}
    root[src] = find(root[src]); //compress
    return root[src];
}   

bool unite(int a, int b) //united or not
{
    a = find(a); b = find(b);
    if(a==b) {return false;}
    if(root[a] > root[b]) swap(a,b);
    root[a] += root[b]; root[b] = a;
    return true;
}

int checkUnion(int a, int b)
{
    a = find(a); b = find(b);
    if(a==b) {return 0;}
    return 1;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0); 
    int n; cin >> n;
    root.assign(2*n, -1);
    int c[n]; 
    int ports[n][4];
    bool used[n];
    int unites[n];
    vector<pair<int, int>> edges;

    for(int i = 0; i < n; i++)
    {
        cin >> c[i] >> ports[i][0] >> ports[i][1] >> ports[i][2] >> ports[i][3];
        for(int j = 0; j < 4; j++) ports[i][j]--;
        edges.pb(mp(c[i], i));
        used[i] = false;
    }

    sort(edges.begin(), edges.end(), greater<pair<int,int>>());

    for(int i = 0; i < edges.size(); i++)
    {
        int cost, v; tie(cost, v) = edges[i];
        unites[i] = checkUnion(ports[v][0], ports[v][1]) + checkUnion(ports[v][2], ports[v][3]);

        if(unites[i] == 2)
        {
            used[i] = true;
            unite(ports[v][0], ports[v][1]); unite(ports[v][2], ports[v][3]);
        }
    }

    //all portals here either unite 0 or unite 1 in this case;

    int total = 0;

    for(int i = edges.size()-1; i >= 0; i--)
    {
        int cost, v; tie(cost, v) = edges[i];
        if(used[i]) continue;

        int p1 = checkUnion(ports[v][0], ports[v][2]) + checkUnion(ports[v][1], ports[v][3]); //number of components it unites
        int p2 = checkUnion(ports[v][0], ports[v][3]) + checkUnion(ports[v][1], ports[v][2]);

        if(p1 == 2) {unite(ports[v][0], ports[v][2]); unite(ports[v][1], ports[v][3]); total += cost; }
        else if(p2 == 2) { unite(ports[v][0], ports[v][3]); unite(ports[v][1], ports[v][2]); total += cost; }
    }

    for(int i = 0; i < edges.size(); i++)
    {
        if(!used[i])
        {
            if(unites[i] == 0) { total += c[i]; }
        }
    }

    cout << total << endl;
}
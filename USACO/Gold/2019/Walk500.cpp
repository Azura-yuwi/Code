//note i think this q was intended to use prims since prims is faster
//i used kruskal and that timed out... T_T

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

vector<int> root;
const ll mod = 2019201997L;

int find(int at)
{
    if(root[at] < 0) return at;
    root[at] = find(root[at]);
    return root[at];
}

bool unite(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b) return false;

    if(root[a] > root[b]) swap(a,b);

    root[a] += root[b]; root[b] = a;
    return true;
}

int main()
{
    ifstream fin("walk.in");
    ofstream fout("walk.out");
    int n,k; cin >> n >> k;
    root.assign(n+2, -1);
    cout << "done " << endl;

    vector<pair<int, pair<int,int>>> edges;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            int dist = i*84 + j*48;
            edges.pb(mp(dist, mp(i,j)));
            cout << "added edge " << dist << " " << i << " " << j << endl;
        }
    }

    sort(edges.begin(), edges.end(), greater<pair<int, pair<int,int>>>());

    cout << "done here" << endl;

    ll ans = edges[edges.size()-1].f;
    ll comps = n; 

    for(int i = 0; i < edges.size(); i++)
    {
        if(unite(edges[i].s.f, edges[i].s.s))
        {
             comps--;
        }
        
        if(comps < k) { ans = edges[i].f; break; }
        cout << i  << " " << comps << endl;
    }

    cout << (ll)(2019201997)-ans << endl;
} 
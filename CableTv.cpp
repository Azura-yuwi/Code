#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_pack
#define mp make_pair
#define f first
#define s second

int root[100];

int find(int a)
{
    if(root[a] < 0)
    {
        return a;
    }

    root[a] = find(root[a]);
    return root[a];
}

bool unite(int a, int b)
{
    a = find(a); b = find(b);

    if(a == b) return false;

    if(root[a] > root[b]) {swap(a,b);}
    //now a has more elements than b

    root[a] += root[b];
    root[b] = a;
    return true;
}

int main()
{
    int n, m; cin >> n >> m;
    pair<int, pair<ll, pair<int,int>>> edges[m];

    for(int i = 0; i < n; i++)
    {
        root[i] = -1;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b,d; ll c; cin >> a >> b >> c >> d; a--;b--;
        edges[i] = mp(d, mp(c, mp(a,b)));
    }

    //cout << "done" << endl;

    sort(edges, edges+m);

    //cout << "sorted" << endl;

    int bad = 0; ll cost = 0;

    for(int i = 0; i < m; i++)
    {
        auto get = edges[i];

        if(unite(get.s.s.f, get.s.s.s))
        {
            //cout << get.s.s.f << " " << get.s.s.s << endl;
            cost += get.s.f;

            if(get.f == 1)
            {
                bad++;
            }
        }
    }

    cout << bad << " " << cost << endl;
}
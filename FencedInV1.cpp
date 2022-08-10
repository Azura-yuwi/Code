#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

vector<int> root;

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
    ifstream fin("fencedin.in");
    ofstream fout("fencedin.out");

    ll A,B; int n,m; fin >> A >> B >> n >> m;
    ll horz[n+2]; ll vert[m+2];
    root.assign((n+1)*(m+1), -1);

    for(int i = 1; i <= n; i++)
    {
        fin >> horz[i];
    }

    horz[0] = 0; horz[n+1] = A;

    sort(horz, horz + n+2);

    for(int i = 1; i <= m; i++)
    {
        fin >> vert[i];
    }

    vert[0] = 0; vert[m+1] = B;

    sort(vert, vert + m+2);

    vector<pair<ll, pair<int,int>>> edges;

    ll hD[n+1]; ll vD[m+1];

    for(int i = 0; i <= n; i++)
    {
        hD[i] = horz[i+1] - horz[i];
        edges.pb(mp(hD[i], mp(0, i)));
    }

    for(int j = 0; j <= m; j++)
    {
        vD[j] = vert[j+1] - vert[j];
        edges.pb(mp(vD[j], mp(1,j)));
    }

    sort(edges.begin(), edges.end());

    ll cost = 0;

    for(auto get : edges)
    {
        if(get.s.f == 0) // remove horizontal stuff
        {
            for(int i = 0; i < m; i++)
            {
                if(unite(i + (m+1)*get.s.s, i+1 +(m+1)*(get.s.s)))
                {
                    cost += get.f;
                }
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(unite(get.s.s + (m+1)*i, get.s.s +(m+1)*(i+1)))
                {
                    cost += get.f;
                }
            }
        }

    }

    fout << cost << endl;
}
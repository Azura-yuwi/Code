#include<bits/stdc++.h>
using namespace std;
#define ll long long
<<<<<<< HEAD
#define pb push_back
#define mp make_pair
#define f first
#define s second

int root[100000];

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
    int n,m; cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        root[i] = -1;
    }

    vector<int> edges;

    for(int i = 1; i <= m; i++)
    {
        int a,b; cin >> a >> b; a--; b--;

        if(unite(a,b))
        {
            edges.pb(i);
        }
    }

    if(edges.size() != n-1)
    {
        cout << "Disconnected Graph";
    }
    else
    {
        for(int i : edges)
        {
            cout << i << endl;
        }
    }
}
=======
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    ifstream fin("walk.in");
    ofstream fout("walk.out");
    int n,k; fin >> n >> k;
    int i = k-1; ll ans = 84*i + 48*n;
    fout << 2019201997L - ans;
}
>>>>>>> 634ba1c599560fbc709b0474b876ee86128269b2

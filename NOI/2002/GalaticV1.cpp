#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int root[30000];
int sroot[30000];
int toRoot[30000];

int find(int a)
{
    if(root[a] < 0) { return a; }

    root[a] = find(root[a]);

    if(root[a] != sroot[a])
    {
        toRoot[a] += toRoot[sroot[a]];
        sroot[a] = root[a];
    }

    return root[a];
}

bool same(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b) return true;
    return false;
}

bool unite(int a, int b)
{
    a = find(a); b = find(b);

    if(a == b) return false;

    toRoot[b] = (-1)*root[a];
    root[a] += root[b]; root[b] = a; sroot[b] = a;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    memset(root, -1, sizeof(root));
    memset(toRoot, 0, sizeof(toRoot));
    memset(sroot, -1, sizeof(sroot));

    for(int i = 0; i < t; i++)
    {
        char c; int a,b; cin >> c >> a >> b; a--; b--;

        if(c == 'M')
        {
            unite(b,a);
        }
        else
        {
            if(!same(a,b)) // were not part of same column
            {
                cout << -1 << endl;
            }
            else
            {
                cout << abs(toRoot[a] - toRoot[b]) - 1 << endl;
            }
        }
    }
}
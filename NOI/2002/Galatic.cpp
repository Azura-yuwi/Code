#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int root[30000];
//int behind[30000];
int toRoot[30000];
vector<int> adj[30000];

int find(int a)
{
    if(root[a] < 0) { return a; }
    root[a] = find(root[a]);
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

    //if(root[a] > root[b]) swap(a,b); 
    //usually does this for optimization but now there is strict order to which one is united to what

    for(int get : adj[b])
    {
        //toRoot[get] += (behind[a]+1); 
        toRoot[get] += (-1*root[a]);
        adj[a].pb(get);
        root[get] = a;
    }

    //toRoot[b] = behind[a]+1; 
    adj[a].pb(b); toRoot[b] = (-1)*root[a];
    //behind[a] += (behind[b] + 1);
    root[a] += root[b]; root[b] = a;
    adj[b].clear();

    return true;
}


int main()
{
    int t; cin >> t;
    memset(root, -1, sizeof(root));
    //memset(behind, 0, sizeof(behind));
    memset(toRoot, 0, sizeof(toRoot));

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
                //cout << toRoot[a] << " " << toRoot[b] << endl;
                cout << abs(toRoot[a] - toRoot[b]) - 1 << endl;
            }
        }
    }
}
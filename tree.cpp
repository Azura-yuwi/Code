#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<int> adj[100000];
pair<int,int> bound[100000];
pair<int,int> vbound[100000];
pair<int,int> vrange[100000];
int b;
bool work;

bool cross(int &s1, int &e1, int &s2, int &e2)
{
    if(max(s1, s2) > min(e1, e2))
    {
        return false;
    }

    s1 = max(s1,s2);
    e1 = min(e1,e2);
    return true;
}

bool dfs(int node)
{
    if(!work)
    {
        return false;
    }

    int st, en; tie(st, en) = vrange[node];

    for(int to: adj[node])
    {
        work = work&dfs(to);
        work = work&cross(st, en, bound[to].f, bound[to].s);

        if(!work)
        {
            return false;
        }
    }

    vbound[node] = mp(st, en);
    bound[node] = mp(st-b, en+b);
    return work;
}

int main()
{
    int n; cin >> n;

    for(int i = 1; i < n; i++)
    {
        int get; cin >> get; get--;
        adj[get].pb(i);
    }

    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        vrange[i] = mp(a,b); 
    }

    int l = 0; int r = 200;

    while(l != r)
    {
        int m = (l+r)/2;
        b = m;
        work = true;
        bool res = dfs(0);

        if(res)
        {
            r = m;
        }
        else
        {
            l = m+1;
        }
    }

    cout << l << endl;
}
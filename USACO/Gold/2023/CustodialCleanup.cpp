//USACO 2023 Open Contest P1
//BFS with crap conditions

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int st1[100005];
int st2[100005];

void upd(bool cse, int i, int val)
{
    if(cse)
    {
        st2[i] = val;
    }
    else
    {
        st1[i] = val;
    }
}

int getv(bool cse, int i)
{
    if(cse)
    {
        return st2[i];
    }
    else
    {
        return st1[i];
    }
}

bool bfs(int n, vector<int> adj[], int c[], int s[], int f[], bool cse)
{
    queue<int> q; 
    unordered_set<int> color[n];
    unordered_set<int> own;

    for(int i = 0; i < n; i++)
    {
        upd(cse, i, 0);
    }

    upd(cse, 0, 3);
    own.insert(s[0]);
    q.push(0);

    while(!q.empty())
    {
        int get = q.front(); q.pop();

        for(int to : adj[get])
        {
            if(getv(cse,to) == 3 || (cse && getv(!cse,to) != 3))
            {
                continue;
            }

            if(own.find(c[to]) != own.end()) //own the color already
            {
                upd(cse,to,3);
                q.push(to); own.insert(s[to]);
            }
            else if (cse && c[to] == s[to])
            {
                upd(cse,to,3);
                q.push(to); own.insert(s[to]);
            }
            else
            {
                color[c[to]].insert(to); upd(cse,to,2);
            }
        }

        for(int add: color[s[get]])
        {
            upd(cse,add,3);
            q.push(add); own.insert(s[add]);
        }

        color[s[get]].clear();
    }

    for(int i = 0; i < n; i++)
    {

        if(getv(cse,i) != 3 && s[i] != f[i])
        {
            return false;
        }
    }

    return true;
}


int main()
{
    int t; cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n,m; cin >> n >> m;

        int c[n], s[n], f[n];
        vector<int> adj[n];

        for(int i = 0; i < n; i++)
        {
            cin >> c[i]; c[i]--;
        }

        for(int i = 0; i < n; i++)
        {
            cin >> s[i]; s[i]--;
        }

        for(int i = 0; i < n; i++)
        {
            cin >> f[i]; f[i]--;
        }

        for(int i = 0; i < m; i++)
        {
            int a,b; cin >> a >> b; 
            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        bool r1 = bfs(n, adj, c, s, f,false);
        bool r2 = bfs(n, adj, c, f, s,true); 

        if (r1 && r2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


}
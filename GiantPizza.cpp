//CSES Graph
//USACO Strongly Connected Components 
//2-SAT problem -----> Kosaraju's Algorithm + Reverse Topological Sort

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<int> adj[200005];
vector<int> rev[200005];
vector<int> ord;
bool visit[200005];
int id[200005];
int outdeg[200005];
vector<int> comptop[200005];
vector<int> member[200005];
int comp; //number of components
int n;

void dfs(int x, int round, int num)
{
    visit[x] = true;
    vector<int> &ad = (round == 0) ? adj[x] : rev[x];

    for(int to : ad)
    {
        if(!visit[to])
        {
            dfs(to, round, num);
        }
        else if(round == 1 && id[to] != 0 && id[to] != num)
        {
            //cout << "TO " << x << " FROM " << to << endl;
            //cout << "ROUND " << round << " NUM " << num << " ID " << id[to] << endl;  
            outdeg[id[to]]++; //reverse topological sort
            comptop[num].pb(id[to]); //where it comes from 
        }
    }

    ord.pb(x);
    
    if(round == 1)
    {
        id[x] = num;
        member[num].pb(x);
    }
}

void clear()
{
    for(int i = 0; i < 2*n; i++)
    {
        visit[i] = false;
    }
}

int notop(int a)
{
    if(a >= n)
    {
        return a-n;
    }

    return a+n;
}

void kosaraju()
{
    clear();

    for(int i = 0; i < 2*n; i++)
    {
        if(!visit[i])
        {
            dfs(i, 0, 0);
        }
    }

    clear();

    comp = 0;

    for(int i = 2*n-1; i >= 0; i--)
    {
        if(!visit[ord[i]])
        {
            comp++;
            dfs(ord[i], 1, comp);
        }
    }
}

void printComponents()
{
    for(int i = 1; i <= comp; i++)
    {
        cout << "COMPONENT NUM " << i << endl;
        cout << "OUT DEGREE  " << outdeg[i] << endl;

        cout << "COMPONENT MEMBERS";

        for(int j : member[i])
        {
            cout << " " << j;
        }

        cout << endl;
        cout << "FROM";

        for(int j : comptop[i])
        {
            cout << " " << j;
        }

        cout << endl;
        cout << endl;
    }
}

int main()
{
    int m; cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        int a,b; char p1, p2; cin >> p1 >> a >> p2 >> b;
        
        if(p1 == '-') {a += n;};
        if(p2 == '-') {b += n;};
        
        a--; b--;

        rev[a].pb(notop(b));
        rev[b].pb(notop(a));

        adj[notop(b)].pb(a);
        adj[notop(a)].pb(b);
    }

    char ans[n];

    for(int i = 0; i < n; i++)
    {
        outdeg[i] = 0;
        ans[i] = '.';
    }

    kosaraju();

    for(int i = 0; i < n; i++)
    {
        if(id[i] == id[i+n])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    queue<int> q;

    for(int i = 1; i <= comp; i++)
    {
        if(outdeg[i] == 0)
        {
            q.push(i);
        }
    }

    //printComponents();

    while(!q.empty())
    {
        int get = q.front(); q.pop();

        for(int i : member[get])
        {
            if(i < n)
            {
                if(ans[i] == '.') //set ones that have not been set before
                {
                    ans[i] = '+';
                }
            }
            else
            {
                if(ans[i-n] == '.')
                {
                    ans[i-n] = '-';
                }
            }
        }

        for(int to : comptop[get])
        {
            outdeg[to]--;
            
            if(outdeg[to] == 0)
            {
                q.push(to);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
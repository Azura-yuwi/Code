//CSES Graph
//DFS?
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

bool visit[100001];
vector<int> adj[100001];
int from[100001];
int start;
bool work;

void dfs(int src)
{
    visit[src] = true;

    for(int i : adj[src])
    {
        if(visit[i] && from[src] != i)
        {
            start = i;
            from[i] = src;
            work = true;
            return;
        }
        
        if(!visit[i])
        {
            from[i] = src;
            dfs(i); // will change status of work

            if(work) //if this dfs returned with a loop to start we can return back
            {
                return;
            }
        }
    }

    return;
}

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    work = false;
    for(int j = 0; j < n; j++)
    {
        from[j] = -1;
        visit[j] = false;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            start = i;
            dfs(i);

            if(work)
            {
                break;
            }
        }

    }

    if(!work)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> path;

        int at = start;

        while(from[at] != start)
        {
            path.push_back((at+1));
            at = from[at];
        }

        path.push_back(at+1);
        path.push_back((start+1));

        cout << path.size() << endl;

        for(int i : path)
        {
            cout << i << " ";
        }
    }

}

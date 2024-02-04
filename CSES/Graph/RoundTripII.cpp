//CSES Graph
//DFS?
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<int> adj[100001];
int p[100001];
unordered_set<int> visit;
bool went[100001];
int n,m;
int start;
bool work;

void dfs(int src)
{   
    visit.insert(src);
    went[src] = true;
    //cout << "SRC " << src << endl;

    for(int to : adj[src])
    {
        //cout << "TO " << to << endl;

        if(visit.find(to) != visit.end() && to != src) 
        {
            start = to;
            work = true;
            p[to] = src;
            //cout << "CYCLE FOUND" << endl;
            return;
        }

        if(!went[to])
        {
            p[to] = src;
            //cout << "NEXT " << to << endl;
            dfs(to);

            if(work)
            {   
                //cout << "RETURN CYCLE" << endl;
                return;
            }
        }
    }
    
    //cout << "DONE " << endl;
    //cout << endl;

    visit.erase(src);

    return;

}   

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        went[i] = false;
        p[i] = -1;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
    }

    work = false;

    for(int i = 0; i < n; i++)
    {
      // cout << "START " << i << " WORK " << work << endl;

        if(!went[i] && !work)
        {
            dfs(i);

            //visit.clear();
        }
    }

    if(!work)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int at = p[start];
    vector<int> ans;
    ans.pb(start+1);

    while(at != start)
    {
        ans.pb(at+1);
        at = p[at];
    }

    ans.pb(start+1);

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for(int i : ans)
    {
        cout << i << " ";
    }
}
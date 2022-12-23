#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int n,m;
vector<int> adj[100005];
unordered_set<int> adj1[100005];
int deg[100005];
bool vis[100005];
unordered_set<int> nums;
int at;

int dfs(int p)
{
    int size = 1;

    /* for(int i = 0; i < adj[p].size();)
    {
        int node = adj[p][i];

        if(nums.find(node) == nums.end())
        {
            adj[p].erase((adj[p].begin()+i));
        }
        else 
        {
            if(!vis[node])
            {
                vis[node] = true;
                int get = dfs(node); 
                size += get;
            }

            i++;
        }
    }*/

    queue<int> kick;

    for(int node : adj1[p])
    {
        if(nums.find(node) == nums.end())
        {
            kick.push(node);
        }
        else
        {
            if(!vis[node])
            {
                vis[node] = true; int get = dfs(node); 
                size += get;
            }
        }
    }

    while(!kick.empty())
    {
        adj1[p].erase(adj1[p].find(kick.front())); kick.pop();
    }

    return size;
}

void upd()
{
    bool none = false;

    while(!none)
    {
        none = true;
        vector<int> toErase;

        for(int i : nums)
        {

            if(deg[i] < at)
            {
                /*
                for(int j : adj[i])
                {
                    deg[j]--;
                }*/

                for(int j : adj1[i])
                {
                    deg[j]--;
                }

                toErase.pb(i);
                none = false;
            }
        }

        for(int i : toErase)
        {
            nums.erase(nums.find(i));
        }
    }

    for(int i : nums)
    {
        vis[i] = false;
    }

    return;
}

int main()
{
    cin >> n >> m;


    for(int i = 0; i < n; i++)
    {
        deg[i] = 0; nums.insert(i); vis[i] = false;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj1[a].insert(b); adj1[b].insert(a);
       // adj[a].pb(b); adj[b].pb(a);
        deg[a]++; deg[b]++;
    }

    at = 1;
    ll ans = 0;

    while(!nums.empty())
    {
        int mSize = 0;

        for(int i : nums)
        {
            if(!vis[i])
            {
                vis[i] = true;
                //cout << "to " << i << endl;
                int get = dfs(i); 
                mSize = max(mSize, get);
            }
        }

        ans = max(ans, (ll)at*mSize);

        at++; upd();
       // cout << "one round fin" << endl;
    }

    cout << ans;

}
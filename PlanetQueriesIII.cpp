//CSES Graph
//
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int to[200005];
int in[200005];
bool visit[200005];
vector<int> cyc[200005];
int cyclength[200005];
int attach[200005];
int cycnum[200005];
int pos[200005];
int n;
int on;

void build()
{
    stack<int> stk;
    queue<int> q;
 
    for(int i = 0; i < n; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }
 
    while(!q.empty())
    {
        int get = q.front(); q.pop();
        stk.push(get);
        visit[get] = true;
        
        in[to[get]]--;
        if(in[to[get]] == 0) 
        {
            q.push(to[get]);
        }
    }
 
    on = 0;
 
    for(int i = 0; i < n; i++) //processing cycles
    {
        if(!visit[i]) //there is a cycle starting at i
        {
            int number = 1; pos[i] = 0;
            visit[i] = true;
            int at = to[i];
            attach[i] = i;
            cyc[on].pb(i); cycnum[i] = on;
 
            while(at != i)
            {
                pos[at] = number; number++;
                visit[at] = true; attach[at] = at;
                cyc[on].pb(at); cycnum[at] = on;
                at = to[at];
            }
 
            on++;
        }
    }
 
    while(!stk.empty())
    {
        int get = stk.top(); stk.pop();
 
        if(cycnum[to[get]] < on) //in a cycle
        {
            pos[get] = -1; //pos = steps from a cycle
            cycnum[get] = cycnum[to[get]] + on;
        }
        else
        {
            pos[get] = pos[to[get]] - 1;
            cycnum[get] = cycnum[to[get]];
        }

        attach[get] = attach[to[get]];
    }
 
    for(int i = 0; i < on; i++)
    {
        cyclength[i] = cyc[i].size();
    }
}


int main()
{
    cin >> n;
 
    for(int i = 0; i < n; i++)
    {
        in[i] = 0;
        visit[i] = false;
        cycnum[i] = -1;
    }
 
    for(int i = 0; i < n; i++)
    {
        int get; cin >> get;
        to[i] = get-1;
        in[get-1]++;
    }
 
    build();
    //check();

    for(int i = 0; i < n; i++)
    {
        int ans = cyclength[cycnum[attach[i]]];
        if(pos[i] < 0)
        {
            ans -= pos[i];
        }

        cout << ans << " ";
    }
}
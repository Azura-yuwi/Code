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

void check()
{
    cout << "THE CYCLES" << endl;
    cout << endl;
    cout << "TOT " << on << endl;
 
    for(int i = 0; i < on; i++)
    {
        cout << "CYCNUM " << i << endl;
        cout << "SIZE "  << cyclength[i] << endl;
        cout << " ";
 
        for(int j : cyc[i])
        {
            cout << j << " ";
        }
 
        cout << endl;
    }
    cout << endl; 
 
    for(int i = 0; i < n; i++)
    {
        cout << "I " << i << " " << cycnum[i] << " " << attach[i] << " " << pos[i] << endl;
    }
}

int query(int src, int des)
{
   if((cycnum[src]%on) != (cycnum[des]%on)) //not part of or attached to same cycle
   {
       return -1;
   }

    int ans = 0;

    if(pos[src] < 0)
    {
        if(pos[des] < 0) //if not, des in cycle src attached to
        {
            if(pos[des] < pos[src]) //destination further from cycle than start;
            {
               return -1;
            }
        
            int at = src;

            while(at != des && ans < pos[des] - pos[src])
            {
                at = to[at];
                ans++;
            }

            if(at != des)
            {
                return -1;
            }
            
            return ans;
        }

        ans -= pos[src];
        src = attach[src];
    }

    if(pos[des] < 0)
    {
        return -1;
    }

    if(pos[src] > pos[des])
    {
        ans += cyclength[cycnum[src]];
    }

    ans += (pos[des] - pos[src]);
    return ans;
}


int main()
{
    int q; cin >> n >> q;
 
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

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        cout << query(a-1, b-1) << endl;
    }
}
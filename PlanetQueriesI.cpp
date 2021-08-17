//CSES Graph 
//?/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int to[200005];
int in[200005];
bool visit[200005];
vector<int> cyc[200005];
int cyclength[200005];
int cycnum[200005];
int pos[200005];
int n;
int on;
int more;

void build()
{
    stack<int> stk;
    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        if(in[i] == 0)
        {
            //cout << "INITIAL " << i << endl;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int get = q.front(); q.pop();
        //cout << "GET " << get << endl;
        stk.push(get);
        visit[get] = true;
        
        in[to[get]]--;
        if(in[to[get]] == 0) 
        {
            q.push(to[get]);
            //cout << "PUSH " << to[get] << endl;
        }
    }

    on = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visit[i]) //there is a cycle starting at i
        {
            //cout << "START " << i << endl;

            int number = 1; pos[i] = 0;
            visit[i] = true;
            int at = to[i];
            cyc[on].pb(i); cycnum[i] = on;

            //cout << "AT " << at << " " << i << endl;

            while(at != i)
            {
                //cout << "AT  " << at << " CYCNUM " << on << " POSITION " << number << endl;
                pos[at] = number; number++;
                visit[at] = true;
                cyc[on].pb(at); cycnum[at] = on;
                at = to[at];
            }

            on++;
        }
    }

    more = on;

    while(!stk.empty())
    {
        int get = stk.top(); stk.pop();

        if(cycnum[to[get]] < on) //in a cycle
        {
            cyc[more].pb(to[get]); //where it is attached to
            cycnum[get] = more;
            pos[get] = -1;
            more++;
        }
        else
        {
            cycnum[get] = cycnum[to[get]];
            pos[get] = pos[to[get]] - 1;
        }
        cyc[cycnum[get]].pb(get);
    }

    for(int i = 0; i < on; i++)
    {
        cyclength[i] = cyc[i].size();
    }

    for(int i = on; i < more; i++)
    {
        cyclength[i] = cyc[i].size() - 1;
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

    cout << "ATTACHMENTS " << endl;
    cout << "TOT " << (more-on) << endl;

    for(int i = on; i < more; i++)
    {
        cout << "CYCNUM " << i << endl;
        cout << "Size " << cyclength[i] << endl;
        cout << " ";

         for(int j : cyc[i])
        {
            cout << j << " ";
        }

        cout << endl;

    }

    for(int i = 0; i < n; i++)
    {
        cout << "I " << i << " " << cycnum[i] << " " << pos[i] << endl;
    }
}

int query(int src, int l)
{
    int num = cycnum[src];
    int cycat = src;

  //  cout << "SRC " << src << " " << pos[src] << endl;

    if(pos[src] < 0) //"out of cycle"
    {
        cycat = cyc[cycnum[src]].at(0);
        num = cycnum[cycat];

        //cout << "UPDATE  "  << cycat << " " << num << endl;

        if(l >= -pos[src]) //will enter cycle
        {
            l += pos[src]; //return l to where it is attached to
            //cout << "L IS " << l << endl;
        }
        else //stop before entering cycle
        {
            return cyc[cycnum[src]][-pos[src] - l];
        }
    }

    l += pos[cycat]; //bring l to start of cycle
   // cout << "TO FRONT " << pos[cycat] << " " << l << endl;


    l %= cyclength[num];

  //  cout << l << endl;

    return cyc[num][l];
}


int main()
{
    int q; cin >> n >> q;

    for(int i = 0; i < n; i++)
    {
        in[i] = 0;
        visit[i] = false;
    }

    for(int i = 0; i < n; i++)
    {
        int get; cin >> get;
        to[i] = get-1;
        in[get-1]++;
    }

    build();
 //   check();

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        cout << query(a-1, b)+1 << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<int> adj[20];
ll cycs[1 << 20];
int num;

void dfs(int p, int node)
{
    for(int to : adj[node])
    {
        if(to == p) //found cycle
        {
            cycs[num]++;
        }
        else if(to > p && !(num&(1<<to))) //not visit
        {
            num += (1<<to);
            dfs(p, to);
            num -= (1<<to);
        }
    }
}

int main()
{
    int n; cin >> n;
    int pref[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> pref[i][j]; pref[i][j]--;
        }
    }

    num = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(pref[i][j] == i)
            {
                break;
            }
            
            adj[i].pb(pref[i][j]);
        }
    }

    ll totalcyc[1<<n];

    for(int i = 0; i < (1<<n); i++)
    {
        cycs[i] = 0;
        totalcyc[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        num = (1<<i);
        cycs[num]++;
        dfs(i,i);
    }

    totalcyc[0] = 1;

    for(int i = 0; i < n; i++) 
    {
        //cout << " on " << i << endl;

        for(int j = 0; j < (1 << i); j++)
        {
            for(int k = 0; k <= j; k++)
            {
                //cout << "j is " << j << " k is " << k << endl;
                if(k&j != k)
                {
                    continue;
                }

                //cout << totalcyc[j-k] << " " << cycs[k+(1<<i)] << endl;
                totalcyc[j + (1<<i)] += (totalcyc[j-k]*cycs[k+(1<<i)]);
            }
        }
    }

    int t; cin >> t;

    for(int i = 0; i < t; i++)
    {
        int h = 0; int g = 0;

        for(int j = 0; j < n; j++)
        {
            char c; cin >> c;
            
            if(c == 'H')
            {
                h += (1<<j);
            }
            else
            {
                g += (1<<j);
            }
        }
        cout << totalcyc[h]*totalcyc[g] << endl;
    }
}
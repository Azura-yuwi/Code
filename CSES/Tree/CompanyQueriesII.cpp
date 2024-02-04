//USACO Guide Binary Jumping
//CSES Tree Algorithms

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int maxn = 200002;
const int maxd = 22;
int lay[maxn][maxd];
int dep[maxn];
vector<int> adj[maxn];

void dfs(int at)
{
    for(int get : adj[at])
    {
        dep[get] = dep[at] + 1;
        dfs(get);
    }
}

int jump(int at, int num)
{
    int d = 0;

    while(num > 0)
    {
        if(num%2 == 1)
        {
            at = lay[at][d];
        }

        d++; num /= 2;
    }

    return at;
}

int main()
{
    int n,q; cin >> n >> q;

    for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxd; j++)
        {
            lay[i][j] = 0;
        }
    }

    for(int i = 2; i <= n; i++)
    {
        int b; cin >> b;
        lay[i][0] = b;
        adj[b].pb(i); 
    }


    for(int j = 1; j < maxd; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            lay[i][j] = lay[lay[i][j-1]][j-1];
        }
    }


    dep[1] = 0;
    dfs(1);

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;

        if(dep[a] > dep[b])
        {
            swap(a,b);
        }

       // cout << dep[a] << " " << dep[b] << endl;

        b = jump(b, dep[b] - dep[a]);

        //cout << a << " " << b << endl;

        if(a == b)
        {
            cout << a << endl;
            continue;
        }

        int lim = 1; 

        while(2*lim <= dep[a])
        {
            lim *= 2;
        }

        for(int j = lim; j > 0; j/=2)
        {
            if(jump(b, j) != jump(a, j))
            {
                b = jump(b,j);
                a = jump(a,j);
            }
        }

        cout << lay[a][0] << endl;
    }
}
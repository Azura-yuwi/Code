#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n;
ll tot[500][500];
ll grid[500][500];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int x, int y)
{
    ll space[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            space[i][j] = -1;
        }
    }

    space[x][y] = 0;
    queue<pair<int,int>> q; q.push(mp(x,y));

    while(!q.empty())
    {
        int nx,ny; tie(nx,ny) = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int tx = nx + dx[i]; int ty = ny + dy[i];

            if(tx < 0 || ty < 0 || tx >= n || ty >= n)
            {
                continue;
            }

            if(space[tx][ty] >= 0)
            {
                continue;
            }

            space[tx][ty] = space[nx][ny] + 1;
            tot[tx][ty] += space[tx][ty]*grid[x][y];
            q.push(mp(tx,ty));
        }
    }
}

void printGrid()
{
    cout << "printing" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << tot[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            tot[i][j] = 0;
        }
    } 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] > 0)
            {
                bfs(i,j);
               // printGrid();
            }
        }
    }

    ll ans = LLONG_MAX;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans = min(ans, tot[i][j]);
        }
    }

    cout << ans;

}
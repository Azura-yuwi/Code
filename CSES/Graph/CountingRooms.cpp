//CSES Graph
//Flood Fill
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int graph[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void fill(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }

    if(graph[x][y] != 1)
    {
        return;
    }

    graph[x][y] = 2;

    for(int i = 0; i < 4; i++)
    {
        fill(x + dx[i], y + dy[i]);
    }
    
    return;
}

void print()
{
    cout << endl;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }

        cout << endl;
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            if(s[j] == '#')
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = 1;
            }
        }
    }

   // print();

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(graph[i][j] == 1)
            {
                ans++;
                fill(i, j);

               // cout << ans;
               // print();
            }
        }
    }

    cout << ans;
}

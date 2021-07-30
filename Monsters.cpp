//CSES Graph
//BFS?
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

int n,m;
int grid[1003][1003];
pair<char, pair<int,int>> from[1003][1003];
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};
bool fin;
int atx, aty;
int startx, starty;
bool work;

queue<pair<int,int>> q;

bool outBound(int x, int y)
{
    if(x <= 0 || x >= n || y <= 0 || y >= m)
    {
        return true;
    }

    return false;
}

bool visit(int x, int y)
{
    if(grid[x][y] != -2)
    {
        return false;
    }

    return true;
}

void bfs()
{
    while(!q.empty())
    {
        pair<int,int> get = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int newx = get.first + dx[i];
            int newy = get.second + dy[i];

            if(outBound(newx, newy))
            {
                if(check)
                {
                    work = true;
                    atx = get.first;
                    aty = get.second;
                    return;
                }

                continue;

            }

            if(visit)
            {
                continue;
            }

            grid[newx][newy] = grid[get.first][get.second] + 1;
            q.push(mp(newx, newy));
        }
    }
}



int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++)
        {
            if(s[j] == '#')
            {
                grid[i][j] = -1;
            }
            else if(s[j] == '.')
            {
                grid[i][j] = -2;
            }
            else if(s[j] == 'M')
            {
                grid[i][j] = 0;
                q.push(mp(i,j)); //should have all monsters in here first;
            }
            else
            {
                grid[i][j] = -2;
                startx = i;
                starty = j;
            }
        }
    }

    bfs();

    q.push(mp(startx, starty));
    grid[startx][starty] = 0;

}
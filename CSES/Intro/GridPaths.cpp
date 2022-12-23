//Recursive Complete Search W/ Pruning

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

char path[48];
bool oc[7][7];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
int tot;

void search(int x, int y, int on)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        int n2x = x + 2*dx[i];
        int n2y = y + 2*dy[i];

        int lx = nx + dx[(i+3)%4];
        int ly = ny + dy[(i+3)%4];

        int rx = nx + dx[(i+1)%4];
        int ry = ny + dy[(i+1)%4];

        if(path[on] != '?' && path[on] != dir[i])
        {
            continue;
        }

        if(nx < 0 || nx > 6 || ny < 0 || ny > 6 || oc[nx][ny])
        {
            //cout << "1st return case " << endl;
            continue;
        }

        if(nx == 6 && ny == 0)
        {
            //cout << "get to " << on << endl;

            if(on == 47)
            {
                tot++;
            }

            return;
        }

        if(n2x < 0 || n2x > 6 || n2y < 0 || n2y > 6 || oc[n2x][n2y]) //can't move forward / forced to turn 
        {
            if(lx >= 0 && lx <= 6 && ly >= 0 && ly <= 6 && !oc[lx][ly])
            {
                if(rx >= 0 && rx <= 6 && ry >= 0 && ry <= 6 && !oc[rx][ry])
                {
                    continue;
                }
            }
        }

        //cout << " to " << nx << " " << ny << endl;

        oc[nx][ny] = true;
        search(nx, ny, on+1);
        oc[nx][ny] = false;     
    }
}

int main()
{
    string str; cin >> str;
    tot = 0;

    for(int i = 0; i < 48; i++)
    {
        path[i] = str[i];
    }

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            oc[i][j] = false;
        }
    }

    oc[0][0] = true;
    search(0,0,0);
    cout << tot;
}
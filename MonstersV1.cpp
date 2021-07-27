//CSES Graph
//BFS?
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int n,m;
int grid[1003][1003];
pair<char, pair<int,int>> from[1003][1003];
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};
bool fin;
char lastdir;
int atx, aty;
int startx, starty;
bool work;

bool outBound(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
    {
        return true;
    }

    return false;
}

bool visit(int x, int y)
{
    if(grid[x][y] == 1)
    {
        return false;
    }

    return true;
}

int main()
{
    cin >> n >> m;
    queue<pair<bool, pair<int,int>>> q;
    work = false;
    
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            if(s[j] == '#')
            {
                grid[i][j] = 0;
            }
            else if(s[j] == '.')
            {
                grid[i][j] = 1;
            }
            else if(s[j] == 'M')
            {
                grid[i][j] = 2;
                q.push(mp(false, mp(i,j))); //should have all monsters in here first;
            }
            else
            {
                grid[i][j] = 2;
                startx = i;
                starty = j;
            }
        }
    }

    q.push(mp(true, mp(startx, starty)));
    grid[startx][starty] = 0;

    while(!work && !q.empty())
    {
        pair<bool, pair<int,int>> get = q.front();
        q.pop();

        //cout << "GET " << get.first << " " << get.second.first << " " << get.second.second << endl;

        for(int i = 0; i < 4; i++)
        {
            int newx = get.second.first + dx[i];
            int newy = get.second.second + dy[i];
           // cout << "AT " << newx << " " << newy << endl;

            if(outBound(newx, newy))
            {
               // cout << "OUTBOUND" << endl;
                if(get.first)
                {
                    //cout << "VALID PATH" << endl;
                    work = true;
                    atx = get.second.first;
                    aty = get.second.second;
                    lastdir = dir[i];
                    break;
                }
                
                continue;
            }

            if(!visit(newx,newy))
            {
                //cout << "NOT VISIT" << endl;
                grid[newx][newy] = 2;
                from[newx][newy] = mp(dir[i], mp(get.second.first, get.second.second));
                q.push(mp(get.first, mp(newx, newy)));
            }
        }

        //cout << endl;

    }

    if(!work)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        vector<char> ans;
        //ans.pb(lastdir);

        while(atx != startx || aty != starty)
        {
            ans.pb(from[atx][aty].first);
            int hold = atx;

            atx = from[atx][aty].second.first;
            aty = from[hold][aty].second.second;
        }

        cout << ans.size() << endl;

        for(int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i];
        }
    }
}
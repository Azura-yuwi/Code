//CSES Graph
//BFS
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int startx, starty, endx, endy;
int graph[1001][1001];
pair<char, pair<int, int>> record[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};
bool fin;

bool valid(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }

    if(graph[x][y] != 1)
    {
        return false;
    }

    return true;
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fin = false;

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

                if(s[j] == 'A')
                {
                    startx = i;
                    starty = j;
                }
                else if(s[j] == 'B')
                {
                    endx = i;
                    endy = j;
                }
            }
        }
    }

    //print();

    //cout << startx << " " << starty << " " << endx << " " << endy << endl;

    queue<pair<int, int>> q;
    q.push(make_pair(startx,starty));
    graph[startx][starty] = 2;

    while(!q.empty() && !fin)
    {
        pair<int, int> get = q.front();
        //cout << "GET  " << get.first << " " << get.second << endl;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int newx = get.first + dx[i];
            int newy = get.second + dy[i];
            //cout << " TO " << newx << " " << newy;

            if(valid(newx, newy))
            {
                //cout << " VALId" << endl;
                //cout << " DIR " << dir[i] << endl;
                graph[newx][newy] = 2;
                record[newx][newy] = make_pair(dir[i], make_pair(get.first, get.second));
                q.push(make_pair(newx, newy));

                if(newx == endx && newy == endy)
                {
                    fin = true;
                    break;
                }
            }
//cout << endl;
        }
    }

    if(!fin)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        vector<char> ans;

        int atx = endx;
        int aty = endy;

        ///cout << " AT " << atx << " " << aty << endl;

        while(atx != startx || aty != starty)
        {   
            ans.push_back(record[atx][aty].first);
            
            //cout << " ADDED " << record[atx][aty].first << endl;

            int hold = atx;
            atx = record[atx][aty].second.first;
            aty = record[hold][aty].second.second;

            //cout << " TO " << atx << " " << aty << endl;
        }

        cout << ans.size() << endl;

        for(int i = ans.size()-1; i >= 0; i--)
        {
            cout << ans[i];
        }
    }
}
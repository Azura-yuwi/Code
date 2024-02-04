//USACO Gold 2020 Open
//Graph -- BFS/DFS?

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    //cout << "started " << endl;
    //ifstream fin("exercise.in");
    //cout << "found file" << endl;

    int n;
    ll d; 
    cin >> n >> d;

    //cout << "read n & d" << endl;

    bool empty[n][n];
    //cout << "made n array" << endl;
    
    int rdist[n][n];
    //cout << "made two arrays" << endl;
    int sdist[n][n];
    bool ans[n][n];
    
    //cout << "made two arrays" << endl;
    vector<pair<int,int>> starts;
    vector<pair<int,int>> rocks;
    
    //cout << "made two arrays" << endl;

    //cout << "initizilzed" << endl;

    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;

        for(int j = 0; j < n; j++)
        {
            if(s[j] == '#')
            {
                empty[i][j] = false;
                rocks.pb(mp(i,j));
            }
            else
            {
                empty[i][j] = true;
            }

            if(s[j] == 'S')
            {
                starts.pb(mp(i,j));
            }

            rdist[i][j] = -1;
            sdist[i][j] = -1;
            ans[i][j] = false;
        }
    }

    //cout << "part 1 done" << endl;

    queue<pair<int,int>> q;

    //dist to rocks

    for(pair<int,int> get : rocks)
    {
        rdist[get.f][get.s] = 0;
        q.push(get);
    }

    while(!q.empty())
    {
        pair<int,int> get = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int x = get.f + dx[i];
            int y = get.s + dy[i];

            if(x < 0 || y < 0 || x >= n || y >= n)
            {
                continue;
            }

            if(rdist[x][y] != -1)
            {
                continue;
            }

            rdist[x][y] = rdist[get.f][get.s] + 1;
            q.push(mp(x,y));
        }
    }

    //cout << "part 2 done" << endl;

    for(pair<int,int> get : starts)
    {
        //cout << "starts " << get.f << " " << get.s << endl;
        sdist[get.f][get.s] = 0;
        q.push(get);
    }

    vector<pair<int,int>> center[n*n]; //center[i] = centers w/ max dist i+1
    while(!q.empty())
    {
        pair<int,int> get = q.front(); q.pop();
        ans[get.f][get.s] = true;
       // cout << "update " << get.f << " " << get.s << endl;
        center[rdist[get.f][get.s] - 1].pb(get); 

        if(sdist[get.f][get.s]/d >= rdist[get.f][get.s]) //would hit rocks if replicate
        {
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            int x = get.f + dx[i];
            int y = get.s + dy[i];
            //   cout << "try " << x << " " << y;

            if(x < 0 || y < 0 || x >= n || y >= n)
            {
               // cout << " outbound " << endl;
                continue;
            }

            if(sdist[x][y] != -1)
            {
                //  cout << " visited " << endl;
                continue;
            }

            if(!empty[x][y]) //rock 
            {
               // cout << " rock" << endl;
                continue;
            }

            if((sdist[get.f][get.s] + 1)/d > rdist[x][y]) //would crash into rocks
            {
               // cout << " crash" << endl;
                continue;
            }

            sdist[x][y] = sdist[get.f][get.s] + 1;
            //cout << " pushed " << endl;
            q.push(mp(x,y));
        }
    }

    vector<pair<int,int>> next;
    vector<pair<int,int>> at;

    for(int i = n*n-1; i >= 0; i--)
    {
        swap(at, next);
        next.clear();

        for(int j = 0; j < at.size(); j++)
        {
            pair<int,int> get = at[j];

            //cout << "at " << get.f << " " << get.s << endl;

            for(int k = 0; k < 4; k++)
            { 
                int x = get.f + dx[k];
                int y = get.s + dy[k];
                
                //cout <<"try " << x << " " << y << endl;

                if(x < 0 || y < 0 || x >= n || y >= n)
                {
                    continue;
                }

                if(ans[x][y])
                {
                    continue;
                }

                if(!empty[x][y])
                {
                    continue;
                }

               // cout << "update reach " << x << " " << y << endl;

                ans[x][y] = true;
                next.pb(mp(x,y));
            }
        }

        for(int j = 0; j < center[i].size(); j++)
        {
            next.pb(center[i][j]);
        }
    }

    int tot = 0;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(ans[i][j])
            {
                tot++;
            }
        }
    }
    cout << tot;
}
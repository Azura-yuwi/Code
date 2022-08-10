//n^2 prim's algorithm here (b/c need n^2 to updates distances anyways)

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    cin.tie(0) -> sync_with_stdio(0); //times out without this for some reason
    int n; cin >> n;
    ll d[n][n];
    ll v[n][n];
    bool visit[n];
    ll min[n];
    ll from[n];

    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
        min[i] = LLONG_MAX;
        from[i] = -1;

        for(int j = 0; j < n; j++)
        {
            cin >> d[i][j];
            v[i][j] = 0;
        }
    } 

    for(int i = 0; i < n; i++)
    {
        if(d[i][i] != 0)
        {
            cout << "NO" << endl;
            return 0;
        }

        for(int j = i+1; j < n; j++)
        {
            if(d[i][j] != d[j][i] || d[i][j] == 0)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    min[0] = 0;
    from[0] = 0;

    for(int i = 0; i < n; i++)
    {
        int get = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visit[j] && (get == -1 || min[get] > min[j])) get = j;
        }
         
        ll dist = min[get];

        for(int j = 0; j < n; j++)
        {
            if(visit[j])
            {
                v[get][j] = v[j][get] = v[j][from[get]] + dist;

                if(v[get][j] != d[get][j])
                {
                    cout << "NO"; return 0;
                }
            }
        }

        visit[get] = true;

        for(int j = 0; j < n; j++)
        {
            if(!visit[j] && d[get][j] < min[j])
            {
                min[j] = d[get][j];
                from[j] = get;
            }
        }
    }

    cout << "YES";
}
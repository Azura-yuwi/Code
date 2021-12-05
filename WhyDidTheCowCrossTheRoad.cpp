//USACO Gold 2017 February 
//Shortest Path --Dijkstra

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
using T = pair<ll, pair<int,int>>;

ll A[101][101];
ll grass[101][101];
int dx[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, 1, -1, 0, 0}; //all places it could end up in 3 moves
int dy[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
int n,t;

void dijkstra(pair<int,int> src)
{
    priority_queue<T, vector<T>, greater<T>> pq;
    A[src.f][src.s] = 0;
    pq.push(mp(0, src));

    while(!pq.empty())
    {
        T get = pq.top(); pq.pop();
        int x = get.s.f; int y = get.s.s; ll d = get.f;

        if(d != A[x][y])
        {
            continue;
        }

        int dist = (n-1 - x) + (n-1-y);

        if(dist <= 2)
        {
            A[n-1][n-1] = min(A[n-1][n-1], d+dist*t);
        } 

        for(int i = 0; i < 16; i++)
        {
            int nx = x + dx[i]; int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            {
                continue;
            }

            if(d+3*t+grass[nx][ny] < A[nx][ny])
            {
                A[nx][ny] = d+3*t+grass[nx][ny];
                pq.push(mp(A[nx][ny], mp(nx,ny)));
            }
        }
    }
}

int main()
{
    ifstream fin("visitfj.in");
    ofstream fout("visitfj.out");
    fin >> n >> t;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fin >> grass[i][j];
            A[i][j] = LLONG_MAX;
        }
    }

    dijkstra(mp(0,0));
    fout << A[n-1][n-1];
}
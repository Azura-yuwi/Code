#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int segTree[1000][1000];
int n,m;

int func(int a, int b)
{
    return (a|b);
}

void buildy(int rw)
{
    for(int col = m-1; col > 0; col--)
    {
        segTree[rw][col] = func(segTree[rw][2*col], segTree[rw][2*col+1]);
    }
}

void buildx()
{
    for(int row = 2*n-1; row >= n; row--)
    {
        buildy(row);
    }

    for(int rw = n-1; rw > 0; rw--)
    {
        for(int cl = 2*m-1; cl >= m; cl--)
        {
            segTree[rw][cl] = func(segTree[2*rw][cl], segTree[2*rw+1][cl]);
        }

        buildy(rw);
    }
}

int colQuery(int row, int y1, int y2)
{
    int ans = 0;

    for(y1 += m, y2 += m; y1 < y2; y1 /= 2, y2 /= 2)
    {
        if(y1&1)
        {
            ans = func(ans, segTree[row][y1++]);
        }
                    
        if(y2&1)
        {
            ans = func(ans, segTree[row][--y2]);
        }
    }

    return ans;
}

int query(int x1, int y1, int x2, int y2) //interval [x1, x2), [y1, y2)
{
    int ans = 0;

    for(x1 += n, x2 += n; x1 < x2; x1 /= 2, x2 /= 2)
    {
        if(x1&1)
        {
            ans = func(ans,colQuery(x1, y1, y2)); x1++;
        }

        if(x2&1)
        {
            x2--; ans = func(ans, colQuery(x2, y1, y2));
        }
    }
        return ans;
}

int main()
{
    int q; cin >> n >> m >> q; //tree.init(n,m);

    for(int i = 0; i < n; i++) //probably need to build directly... otherwise this is n*m
    {
        for(int j = 0; j < m; j++)
        {
            int v; cin >> v; segTree[i+n][j+m] = v;
        }
    }

    buildx();

    for(int i = 0; i < q; i++)
    {
        int x1, y1, x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1-1, y1-1, x2, y2) << endl;
    }
}
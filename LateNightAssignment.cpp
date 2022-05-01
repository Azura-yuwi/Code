#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

template<class T> struct d2_segement_tree
{
    const T INF = 0;
    int r,c; vector<vector<T>> segTree;

    void printTree()
    {
        cout << "Printing Tree" << endl;
        for(int i = 0; i < 2*r; i++)
        {
            for(int j = 0; j < 2*c; j++)
            {
                cout << segTree[i][j] << " ";
            }
            cout << endl;
        }
    }

    int func(T a, T b)
    {
        //cout << a << " " << b << " " << (a|b) << endl;
        return (a|b);
     }

    void init(int row, int col)
    {
        r = row; c = col;

        for(int i = 0; i < 2*row; i++)
        {
            vector<T> add; add.assign(2*col, INF);
            segTree.pb(add);
        }
    }

    void upd(int rw, int cl, T v)
    {
        segTree[rw += r][cl += c] = v;

        for(int col = cl/2; col > 0; col /= 2)
        {
            segTree[rw][col] = func(segTree[rw][2*col], segTree[rw][2*col+1]);
        }

        for(rw /= 2; rw > 0; rw /= 2)
        {
            segTree[rw][cl] = func(segTree[2*rw][cl], segTree[2*rw+1][cl]);

            for(int col = cl/2; col > 0; col /= 2)
            {
                segTree[rw][col] = func(segTree[rw][2*col], segTree[rw][2*col+1]);
            }
        }
    }

    T query(int x1, int y1, int x2, int y2) //interval [x1, x2), [y1, y2)
    {
        T ans = 0;

        for(x1 += r, x2 += r; x1 < x2; x1 /= 2, x2 /= 2)
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

    T colQuery(int row, int y1, int y2)
    {
        T ans = 0;

        for(y1 += c, y2 += c; y1 < y2; y1 /= 2, y2 /= 2)
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
};

d2_segement_tree<int> tree;

int main()
{
    int n,m,q; cin >> n >> m >> q; tree.init(n,m);

    for(int i = 0; i < n; i++) //probably need to build directly... otherwise this is n*m
    {
        for(int j = 0; j < m; j++)
        {
            int v; cin >> v; tree.upd(i,j,v);
        }
    }

    for(int i = 0; i < q; i++)
    {
        int x1, y1, x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << tree.query(x1-1, y1-1, x2, y2) << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

vector<int> segTree;
int sz;

void upd(int p, int v)
{
    segTree[p += sz] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        segTree[p] = max(segTree[2*p], segTree[2*p+1]);
    }
}

int query(int l, int r)
{
    int ans = 0;

    for(l += sz, r += sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ans = max(ans, segTree[l++]);
        }

        if(r&1)
        {
            ans = max(ans, segTree[--r]);
        }
    }

    return ans; 
}


void printTree()
{
    cout << "printTree " << endl;
    for(int i : segTree)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << "end " << endl;
}

int main()
{
    int n,m; cin >> n >> m;
    int hotel[n]; sz = n;
    segTree.assign(2*n, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> hotel[i];
        upd(i, hotel[i]);
    }

    //printTree();

    for(int i = 0; i < m; i++)
    {
        int g; cin >> g;

        //first true

        int l = 0; int r = n;

        while(l != r)
        {
            int mid = l + (r-l)/2; 
            int queryVal = query(0, mid+1);
           // cout << l << " " << r << " " << mid << " " << queryVal << " " << g << endl;

            if(queryVal >= g)
            {
                r = mid;
            } 
            else
            {
                l = mid+1; 
            }
        }
        
        if(l >= n)
        {
            cout << "0 " ;
        }
        else
        {
            cout << (l+1) << " ";
            hotel[l] -= g;
            upd(l, hotel[l]);
           // printTree();
        }
    }
}
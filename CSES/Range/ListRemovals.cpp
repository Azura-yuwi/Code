#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

vector<int> segTree;
int sz;

int func(int &a, int &b)
{
    return a+b;
}

void upd(int p, int v)
{
    segTree[p += sz] = v;

    for(p /= 2; p > 0; p /= 2)
    {
        segTree[p] = func(segTree[2*p],segTree[2*p+1]);
    }
}

int query(int l, int r)
{
    int ans = 0;

    for(l += sz, r += sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ans = func(ans, segTree[l++]);
        }

        if(r&1)
        {
            ans = func(ans, segTree[--r]);
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
    int n; cin >> n; sz = n; segTree.assign(2*n, 0);
    int v[n];
    int pres[n];

    for(int i = 0; i < n; i++)
    {
        cin >> v[i]; pres[i] = 1; upd(i, 1);
    }

    for(int i = 0; i < n; i++)
    {
        int rem; cin >> rem;

        int l = 0; int r = n;

        while(l < r)
        {
            int mid = l + (r-l)/2;
            int val = query(0, mid+1);

            if(val >= rem)
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }

        cout << v[l] << " ";
        pres[l] = 0; upd(l, 0);
    }
}
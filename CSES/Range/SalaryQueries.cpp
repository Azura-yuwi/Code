//USACO Guide Point Update Range Sum
//CSES Range Queries
//Segment Trees/BinaryIndexTree?
//coordinate compression

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

template<class T> struct segment_tree
{
    const T INF = 0;
    int n; vector<T> segTree;

    T func(T a, T b)
    {
        return a+b;
    }

    void init(int size)
    {
        n = size;
        segTree.assign(2*n, 0);
    }

    void upd(int p, T v) //v = +- 1
    {
        segTree[p += n] += v;

        for(p /= 2; p > 0; p /= 2)
        {
            segTree[p] = func(segTree[2*p], segTree[2*p+1]);
        }
    }

    T query(int l, int r) //interval [l, r)
    {
        T ans = 0;
    
        for(l += n, r += n; l < r; l /= 2, r /= 2) 
        {
            if(l&1)
            {
                ans += segTree[l++]; //same as func(ans, segTree[l]); l++
            }

            if(r&1)
            {
                ans += segTree[--r]; //same as func(ans, segTree[r-1]); r--;
            }
        }

        return ans;
    }
};

segment_tree<int> tree;

int main()
{
    int n,q;
    cin >> n >> q;

    int sal[n];
    vector<int> vals;

    for(int i = 0; i < n; i++)
    {
        cin >> sal[i]; vals.pb(sal[i]);
        //tree.upd(sal[i], 1);
    }

    vector<pair<char, pair<int,int>>> queries;

    for(int i = 0; i < q; i++)
    {
        char type; cin >> type;
        int a,b; cin >> a >> b;
        queries.pb(mp(type, mp(a,b)));

        if(type == '!')
        {
            //change salary of a to b
            vals.pb(b);
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    tree.init(vals.size());

    for(int i = 0; i < n; i++)
    {
        int index = lower_bound(vals.begin(), vals.end(), sal[i]) - vals.begin();
        tree.upd(index, 1);
    }

    for(int i = 0; i < q; i++)
    {
        char type; type = queries[i].first;
        int a,b; tie(a,b) = queries[i].second;

        if(type == '!')
        {
            //change salary of a to b
            a--;
            int index = lower_bound(vals.begin(), vals.end(), sal[a]) - vals.begin();
            //cout << "testing a " << sal[a] << " " << index << endl;
            tree.upd(index, -1);
            index = lower_bound(vals.begin(), vals.end(), b) - vals.begin();
            //cout << "testing b " << b << " " << index << endl;
            tree.upd(index, 1);
            sal[a] = b;
        }
        else
        {
            int left = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
            int right = upper_bound(vals.begin(), vals.end(), b) - vals.begin();
            cout << tree.query(left, right) << endl;
        }
    }
}
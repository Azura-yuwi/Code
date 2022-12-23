#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<ll> sum;
vector<ll> pre;
vector<pair<int,int>> pos; //left, right
vector<ll> post;
vector<ll> tree;
int sz;

void build()
{
    for(int i = 0; i < sz; i++)
    {
        pos[i + sz] = mp(i, i);
    }
    for(int i = sz-1; i >= 0; i--)
    {
        pos[i] = mp(pos[2*i].first, pos[2*i+1].second);
    }
}

void upd(int p, ll v)
{
    sum[p += sz] = v; pre[p] = v; post[p] = v; tree[p] = max(v, (ll)0);

    for(p /= 2; p > 0; p /= 2)
    {
        sum[p] = sum[2*p] + sum[2*p+1];
        pre[p] = max(pre[2*p], pre[2*p+1] + sum[2*p]);
        post[p] = max(post[2*p+1], post[2*p] + sum[2*p+1]);
        tree[p] = max(tree[2*p], tree[2*p + 1]);
        tree[p] = max(tree[p], max((ll)0,post[2*p]) + max((ll)0,pre[2*p+1]));
    }
}

void printTree()
{
    cout << "printing sum tree" << endl;
    for(int i : sum)
    {
        cout << i << " ";
    }

    cout << endl;

    cout << "printing prefix tree " << endl;

    for(auto get : pre)
    {
        cout << get << " ";
    }

    cout << endl;
    cout << "printing postFix tree " << endl;

    for(auto get : post)
    {
        cout << get << " ";
    }
    cout << endl;
    cout << "printing tree " << endl;

    for(auto get: tree)
    {
        cout << get << " ";
    }

    cout << endl;
}

int main()
{
    int n,m; cin >> n >> m; sz = n;
    sum.assign(2*n, 0); pre.assign(2*n, 0); post.assign(2*n, 0); tree.assign(2*n, 0);
    
    for(int i = 0; i < n; i++)
    {
        int get; cin >> get; upd(i, get);
    }
    
    printTree();

    for(int i = 0; i < m; i++)
    {
        int p; ll v; cin >> p >> v; p--;
        upd(p,v); 
        cout << tree[1] << endl;
    }
}
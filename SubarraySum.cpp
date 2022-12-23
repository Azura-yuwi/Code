#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<ll> sum;
vector<pair<ll,int>> pre;
vector<pair<int,int>> pos; //left, right
vector<pair<ll,int>> post;
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
    sum[p += sz] = v;
    pre[p] = mp(v, p-sz); post[p] = mp(v, p-sz);

    for(p /= 2; p > 0; p /= 2)
    {
        sum[p] = sum[2*p] + sum[2*p+1];

        if(pre[2*p].f <= pre[2*p+1].f + sum[2*p])
        {
            pre[p] = pre[2*p];
        }
        else
        {
            pre[p] = mp(pre[2*p+1].f + sum[2*p], pre[2*p+1].s);
        }

        if(post[2*p+1].f <= post[2*p].f + sum[2*p+1])
        {
            post[p] = post[2*p+1];
        }
        else
        {
            post[p] = mp(post[2*p].f + sum[2*p+1], post[2*p].s);
        }

        //pre[p] = mim(pre[2*p], pre[2*p+1] + sum[2*p]);
        //post[p] = min(post[2*p+1], post[2*p] + sum[2*p+1]);
    }
}

ll sQuery(int l, int r)
{
    ll ans = 0;
    
    for(l += sz, r += sz; l < r; l /= 2, r/= 2)
    {
        if(l&1)
        {
            ans += sum[l++];
        }

        if(r&1)
        {
            ans += sum[--r];
        }
    }

    return ans;
}

pair<ll,int> preQuery(int l, int r)
{
    ll ans = 0;
    int at = -1;

    for(l += sz, r += sz; l < r; l /= 2, r /= 2)
    {
        if(l&1)
        {
            ll check = pre[l].f + sQuery(0, pos[l].first);

            if(ans > check)
            {
                ans = check; at = pre[l].s;
            }
            else if(ans == check)
            {
                if(at > pre[l].s)
                {
                    at = pre[l].s;
                }
            } 

            l++;
        }

        if(r&1)
        {
            r--;
            ll check = pre[r].f + sQuery(0, pos[r].first);
            if(ans > check)
            {
                ans = check; at = pre[r].s;
            }
            else if(ans == check)
            {
                if(at > pre[r].s)
                {
                    at = pre[r].s;
                }
            } 
        }
    }

    return mp(ans, at);
}

pair<ll, int> postQuery(int l, int r)
{
    ll ans = 0; int at = -1; 

    for(l += sz, r += sz; l < r; l /= 2, r/= 2)
    {
        if(l&1)
        {
            ll check = post[l].f + sQuery(pos[l].s+1, sz);
            if(ans > check)
            {
                ans = check; at = post[l].s;
            }
            else if(ans == check)
            {
                at = max(at, post[l].s);
            } l++;
        }

        if(r&1)
        {
            r--; ll check = post[r].f + sQuery(pos[r].s+1, sz);
            if(ans > check)
            {
                ans = check; at = post[r].s;
            }
            else if(ans == check)
            {
                at = max(at, post[r].s);
            }
        }
    }

    return mp(ans, at);
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
        cout << "(" << get.f << "," << get.s << ") ";
    }

    cout << endl;
    cout << "printing postFix tree " << endl;

    for(auto get : post)
    {
        cout << "(" << get.f << "," << get.s << ") ";
    }

    cout << endl;
}

int main()
{
    int n,m; cin >> n >> m; sz = n;
    sum.assign(2*n, 0); pre.assign(2*n, mp(2e14+5, -1));  post.assign(2*n, mp(2e14+5, -1)); pos.assign(2*n, mp(0,0));
    build(); 

    for(int i = 0; i < n; i++)
    {
        int get; cin >> get; upd(i, get);
    }

   // printTree();

    for(int i = 0; i < m; i++)
    {
        int p; ll v; cin >> p >> v; p--;
        upd(p, v);

        ll tot = sQuery(0, n);
        pair<ll,int> prefix = preQuery(0, n);
        pair<ll, int> postfix = postQuery(0, n);

        ll ans = max((ll)0, tot); 
       // cout << tot << endl;

        if(prefix.s != -1)
        {
            pair<ll, int> get = postQuery(prefix.s+1, n);
            ans = max(ans, tot - prefix.f - get.f);
           // cout << "pre " << prefix.f << " " << prefix.s << " " << get.f << " " << get.s << endl;
        }

        if(postfix.s != -1)
        {
            pair<ll,int> get = preQuery(0, postfix.s);
            ans = max(ans, tot - postfix.f - get.f);
           // cout << "post " << postfix.f << " " << postfix.s << " " << get.f << " " << get.s << endl;
        }

        //ans = max(ans, tot - prefix.f);
       // ans = max(ans, tot - postfix.f);

        // if(postfix.s != -1 && postfix.s != -1 && prefix.s <= postfix.s) 
        //{
            //ans = max(ans, tot - prefix.f - postfix.f);
        //}

        cout << ans << endl;
        //cout << "total " << tot << " preFix " << prefix.f << " " << prefix.s << " postfix " << postfix.f  << " " << postfix.s << endl;
    }
}
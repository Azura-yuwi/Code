//Convex Hull 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

bool checkCvx(pair<ll,ll> &a, pair<ll,ll> &b, pair<ll,ll> &c) //in order of x, 
{
    if((b.s - a.s)*(c.f - a.f) > (c.s - a.s)*(b.f - a.f)) return true; //slope of AC is <= slope of AB -- > B is above/on AC
    return false;
}

struct CHull
{
    vector<pair<ll,ll>> hull;
    int cur = 0;

    void insert(ll x, ll y)
    {
        pair<ll,ll> toAdd = mp(x,y);

        while(hull.size() > 1 && checkCvx(hull[hull.size() - 2], hull[hull.size() - 1], toAdd))
        {
            hull.pop_back();
        }

        hull.pb(toAdd);
    }

    ll query(ll b) //o(n) overall 
    {
        ll ans = hull[cur].s - hull[cur].f*b;

        while(cur+1 < hull.size() && hull[cur+1].s - hull[cur+1].f*b < ans)
        {
            cur++;
            ans = hull[cur].s - hull[cur].f*b;
        }

        return ans;
    }
    
    ll query2(ll b) //O(log(n)) each time so nlogn overall (worse with more queries)
    {
        ll ans = hull[0].s - hull[0].f*b; //y-intercept
        int del = (1<<30);
        int cur = 0;

        while(del) //del > 0
        {
            if(cur + del < hull.size() && b*(hull[cur + del].f - hull[cur+del-1].f) > (hull[cur+del].s - hull[cur+del-1].s))
            {
                cur += del; //form of binary searching (?)
                //only works b/c the equation should be strictly increasing up until a certain point (?)
                ans = hull[cur].s - hull[cur].f*b;
            }

            del /= 2;
        }

        return ans;
    }

    ll query1(ll b) //og one from chat; i think has some slight logic issues; fixed in query2(?)
    {
        ll ans = hull[0].s - hull[0].f*b; //y-intercept
        int del = (1<<30);
        int cur = 0;

        while(del) //del > 0
        {
            if(cur + del < hull.size() && hull[cur + del].s - hull[cur + del].f * b < ans)
            {
                cur += del;
                ans = hull[cur].s - hull[cur].f*b;
            }

            del /= 2;
        }
        return ans;
    }
};

int main()
{
    int n; ll c; cin >> n >> c;
    ll h[n];

    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    ll dp[n];

    for(int i = 0; i < n; i++)
    {
        dp[i] = LLONG_MAX;
    }

    dp[0] = 0;
    CHull hull; hull.insert(2*h[0], dp[0]+h[0]*h[0]);

    for(int i = 1; i < n; i++)
    {
        ll get = hull.query(h[i]);
        dp[i] = get + h[i]*h[i] + c;
        hull.insert(2*h[i], dp[i] + h[i]*h[i]);
    }

    cout << dp[n-1];
}
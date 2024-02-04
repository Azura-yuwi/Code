//CSES Geometry
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

// might be on same line but not interseting -->  chcked by this 
bool c1(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3, pair<ll,ll> p4)
{
    ll x1,y1,x2,y2,x3,y3,x4,y4; tie(x1, y1) = p1; tie(x2,y2) = p2; tie(x3,y3) = p3; tie(x4,y4) = p4;
    
    ll mx = max(max(x1,x2), max(x3,x4)); ll mnx = min(min(x1,x2), min(x3,x4));
    ll my = max(max(y1,y2), max(y3,y4)); ll mny = min(min(y1,y2), min(y3,y4));

    //ll mx1 = max(x1,x2); ll mx2 = min(x1,x2); ll mx3 = max(x3,x4); ll mx4 = min(x3,x4);
    //ll my1 = max(y1,y2); ll my2 = min(y1,y2); ll my3 = max(y3,y4); ll mx4 = min(x3,x4);

    if(mx - mnx > abs(x1 - x2) + abs(x3 -x4))
    {
        return false;
    }

    if(my - mny > abs(y1 - y2) + abs(y3 - y4))
    {
        return false;
    }

    return true;
}

ll collinear(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3)
{
    ll x1,y1,x2,y2,x3,y3; tie(x1, y1) = p1; tie(x2,y2) = p2; tie(x3,y3) = p3;

    pair<ll,ll> v1 = mp(x2 - x1, y2 - y1);
    pair<ll,ll> v2 = mp(x3 - x1, y3 - y1);
    ll num = v2.s*v1.f - v1.s*v2.f;

    if (num > 0)
    {
        return 1;
    }
    else if (num == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int t; cin >> t;

    for(int i = 0; i < t; i++)
    {
        ll x1,y1,x2,y2,x3,y3,x4,y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pair<ll,ll> p1 = mp(x1,y1); pair<ll,ll> p2 = mp(x2,y2);  pair<ll,ll> p3 = mp(x3,y3); pair<ll,ll> p4 = mp(x4,y4);
        ll n1 = collinear(p1, p2, p3); ll n2 = collinear(p1, p2, p4); 

        ll n4 = collinear(p3,p4,p1); ll n3 = collinear(p3,p4,p2);

        //cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;

        if(n1*n2 <= 0 && n4*n3 <= 0 && c1(p1,p2,p3,p4))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
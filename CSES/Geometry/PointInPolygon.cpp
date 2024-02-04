//CSES Geometry
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

bool c1(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3, pair<ll,ll> p4)
{    
    ll mx = max(max(p1.f,p2.f), max(p3.f,p4.f)); ll mnx = min(min(p1.f,p2.f), min(p3.f,p4.f));
    ll my = max(max(p1.s,p2.s), max(p3.s,p4.s)); ll mny = min(min(p1.s,p2.s), min(p3.s,p4.s));

    if(mx - mnx > abs(p1.f - p2.f) + abs(p3.f - p4.f))
    {
        return false;
    }

    if(my - mny > abs(p1.s - p2.s) + abs(p3.s - p4.s))
    {
        return false;
    }

    return true;
}

ll collinear(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3)
{
    pair<ll,ll> v1 = mp(p2.f - p1.f, p2.s - p1.s);
    pair<ll,ll> v2 = mp(p3.f - p2.f, p3.s - p2.s);
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

int intersect(pair<ll,ll>p1, pair<ll,ll> p2, pair<ll,ll> p3, pair<ll,ll> p4)
{
    ll n1 = collinear(p1, p2, p3); ll n2 = collinear(p1, p2, p4); 
    ll n3 = collinear(p3,p4,p1); ll n4 = collinear(p3,p4,p2);

    if(n1*n2 <= 0 && n4*n3 <= 0 && c1(p1,p2,p3,p4))
    {
        if(n1*n2 == 0 || n3*n4 == 0) //get rid of intersect at boundary for this prob
        {
            return 0;
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n,m ; cin >> n >> m;
    pair<ll,ll> pnts[n];

    for(int i = 0; i < n; i++)
    {
        ll a,b; cin >> a >> b;
        pnts[i] = mp(a,b);
    }

    for(int i = 0; i < m; i++)
    {
        ll x,y; cin >> x >> y; pair<ll,ll> pnt = mp(x,y); pair<ll,ll> pntc = mp(1LL + INT_MAX,y);

        // check if on boundary
        //check if inside or outside
        
        ll num = 0;
        ll vert = 0;
        bool bound = false;

        for(int i = 0; i < n; i++)
        {
            if(collinear(pnt, pnts[i], pnts[(i+1)%n]) == 0 && c1(pnt, pnt, pnts[i], pnts[(i+1)%n]))
            { 
                bound = true;
                break;
            }

            int get = intersect(pnt, pntc, pnts[i], pnts[(i+1)%n]);

            if(get > 0)
            {
                num++;
            }

            //if intersect at vertex -- different cases

            if(collinear(pnt, pntc, pnts[i]) == 0 && c1(pnts[i], pnts[i], pnt, pntc))
            {
                if (collinear(pnt, pntc, pnts[(i+1)%n])*collinear(pnt, pntc, pnts[(i+n-1)%n]) == -1)
                {
                    num++;
                }
                else if(collinear(pnt, pntc, pnts[(i+1)%n]) == 0)
                {
                   if(collinear(pnt, pntc, pnts[(i+n-1)%n])*collinear(pnt, pntc, pnts[(i+2)%n]) == -1)
                    {
                       num++;
                   }
                }
           }
        }

        if(bound)
        {
            cout << "BOUNDARY" << endl;
        }
        else if(num%2 == 0)
        {
            cout << "OUTSIDE" << endl;
        }
        else
        {
            cout << "INSIDE" << endl;
        }
    }
}
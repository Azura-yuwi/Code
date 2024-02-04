//CSES Geometry
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int t; cin >> t;

    for(int i = 0; i < t; i++)
    {
        ll x1,y1,x2,y2,x3,y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        pair<ll,ll> v1 = mp(x2 - x1, y2 - y1);
        pair<ll,ll> v2 = mp(x3 - x1, y3 - y1);
        ll num = v2.s*v1.f - v1.s*v2.f;

        if(num == 0)
        {
            cout << "TOUCH" << endl;
        }
        else if (num < 0)
        {
            cout << "RIGHT" << endl;
        }
        else
        {
            cout << "LEFT" << endl;
        }
    }
}
//CSES Intro Set
//Mathish?

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find(ll r, ll c)
{
    if(r > c)
    {
        return (r*r-c+1);
    }
    else
    {
        return ((c-1)*(c-1) + r);
    }
}

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        ll x,y;
        cin >> x >> y;

        if(max(x,y)%2 == 0)
        {
            cout << find(x,y) << endl;
        }
        else
        {
            cout << find(y,x) << endl;
        }
    }


}
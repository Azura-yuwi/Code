//CSES/USACO Guide
//Monotonic Stack

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
   int n;
   cin >> n;

   ll val[n+1];
   val[0] = -1;

   for(int i = 1; i <= n; i++)
   {
       cin >> val[i];
   }

    ll left[n];
    ll right[n];

    stack<pair<ll,int>> stk;
    stk.push(mp(-1,0));

    for(int i = 1; i <= n; i++)
    {
        while(!stk.empty() && stk.top().first >= val[i])
        {
            stk.pop();
        }

        left[i] = stk.top().second;
        stk.push(mp(val[i], i));
    }


    while(!stk.empty())
    {
        stk.pop();
    }

    stk.push(mp(-1, n+1));

    for(int i = n; i > 0; i--)
    {
        while(!stk.empty() && stk.top().first >= val[i])
        {
            stk.pop();
        }

        right[i] = stk.top().second;
        stk.push(mp(val[i],i));
    }

    ll area = 0;

    for(int i = 1; i <= n; i++)
    {
        area = max(area, val[i]*(right[i] - left[i] - 1));
    }

    cout << area;
}
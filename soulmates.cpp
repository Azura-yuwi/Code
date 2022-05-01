#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

void solve()
{
    int a,b; cin >> a >> b;
    vector<int> alist; vector<int> blist;

    while(a > 1)
    {
        alist.pb(a);

        if(a%2 == 0)
        {
            a /= 2;
        }
        else
        {
            a++;
        }
    }

    alist.pb(a);

    while(b > 1)
    {
        blist.pb(b);

        if(b%2 == 0)
        {
            b /= 2;
        }
        else
        {
            b--;
        }
    }

    blist.pb(b);
    int result = INT_MAX;
    int p1 = 0;

    for(int i = 0; i < alist.size(); i++)
    {
        if(alist[i] > blist[p1] && p1 == 0)
        {
            continue;
        }

        while(blist[p1] > alist[i])
        {
            p1++;
        }

        while(blist[p1] < alist[i])
        {
            p1--;
        }

        result = min(result, p1 + i + blist[p1] - alist[i]);
    }

    cout << result << endl;
}

int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        solve();
    }
}
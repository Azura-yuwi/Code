//GPL Problem 5

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
    int n; cin >> n;

    int val[n];
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<pair<int, int>> ob;
    ob.pb(mp(0,0));

    int at = 0;

    while(at < n)
    {
        int prev = at; at++;

        while(at < n && val[at] == val[prev])
        {
            at++;
        }

        ob.pb(mp(val[prev], at - prev));
    }

    
}
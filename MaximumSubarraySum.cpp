//CSES Sorting and Searching

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    ll val[n+1];

    for(int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    ll pre[n+1];
    pre[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        pre[i] = pre[i-1] + val[i];
    }

    stack<pair<ll,int>> stk;
    stk.push(mp(pre[n], n));

    for(int i = n-1; i > 0; i--)
    {
        if(pre[i] > stk.top().first) //monotonic stack
        {
            stk.push(mp(pre[i], i));
        }
    }

    ll ans = LLONG_MIN; 

    for(int i = 0; i < n; i++)
    {
        while(stk.top().second <= i) 
        {
            stk.pop();
        }
        //cout << "TOP " << stk.top().first << " " << stk.top().second << endl;
        //cout <<  "I " << i << " " << pre[i] << endl;
        ans = max(ans, stk.top().first - pre[i]);
    }

    cout << ans;

}
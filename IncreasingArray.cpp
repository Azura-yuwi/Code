//CSES Intro Set
//Brute Force

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    int hold;
    cin >> hold;
    int cur;
    ll ans = 0;

    for(int i = 1; i < n; i++)
    {
        cin >> cur;
        if(cur < hold)
        {
            ans += (hold-cur);
        }
        else
        {
            hold = cur;
        }

        //cout << ans << endl;
    }

    cout << ans;
}
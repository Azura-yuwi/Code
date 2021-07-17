//CSES Intro Set
// Brute Force

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int few[4] = {0,6,28,96};

    for(int i = 0; i < min(4,n); i++)
    {
        cout << few[i] << endl;
    }

    for(ll i = 5; i <= n; i++)
    {
        ll ans = (i-4)*(i-4)*(i*i-9)/2;
        ans += 4*i*i*i - 8*i*i-24*i+64;
        cout << ans << endl;
    }
}
//CSES Intro Set
//Calculate Powers Fast (the Binary method)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll mod = 1e9 + 7;
    int n;
    cin >> n;

    ll ans = 1;
    ll two = 2;

    while(n > 0)
    {
        if(n%2 == 1)
        {
            ans*= two;
            ans %= mod;
        }

        n /= 2;
        two = two*two;
        two %= mod;
    }

    cout << ans;
}

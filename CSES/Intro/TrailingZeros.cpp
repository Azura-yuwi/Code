//CSES Intro Set
//Factorials? Ad Hocs?

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll factors(int n, int p)
{
    ll ans = 0; 
    
    while(n > 0)
    {
        ans += (ll)n/p;
        n /= p;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    ll ans = factors(n, 5);

    cout << ans;
}
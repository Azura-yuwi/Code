//GPL Problem 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n; cin >> n;

    ll ans = 0; 

    for(int i = 0; i < n; i++)
    {
        int get; cin >> get;

        if(get%2 == 0)
        {
            ans += get;
        }
    }

    cout << ans;
}
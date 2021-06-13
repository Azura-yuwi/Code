#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int diff[n];
    int h[n];

    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        diff[i] = h[i+1]-h[i];
    }
    

    int ans = n;
    ans += h[0];
    ans +=h[n-1];

    for(int i = 0; i < n-1; i++)
    {
        ans += abs(diff[i]);
    }

    cout << ans;


}
//CSES Intro Set
// Brute Force

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;

    ll sum = n*(n+1)/2;

    if(sum%2 == 1)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    if(n%2 == 0)    
    {
        cout << n/2 << endl;

        for(int i = 1; i <= n/4; i++)
        {
            cout << i << " " << (n-i+1) << " ";
        }

        cout << endl;

        cout << n/2 << endl;

        for(int i = n/4 + 1; i <= n/2; i++)
        {
            cout << i << " " << (n-i+1) << " ";
        }
    }
    else
    {
        cout << (n/2) << endl;

        for(int i = 1; i <= n/4; i++)
        {
            cout << i << " " << (n-i) << " ";
        }

        cout << n << endl;

        cout << n - (n/2) << endl;

        for(int i = n/4 + 1; i <= n/2; i++)
        {
            cout << i << " " << (n-i) << " ";
        }
    }

}
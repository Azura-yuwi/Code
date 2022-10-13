#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

void solve(int n)
{
    cout << n << endl;
    int a[n];
    for(int i = 0; i < n; i++) {a[i] = i+1; cout << a[i] << " "; }

    cout << endl;

    for(int i = n-2; i >= 0; i--)
    {
        a[i+1] = (i+1); a[i] = n;
        //swap(a[i], a[i+1]);

        for(int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n; cin >> n;
        solve(n);
    }
}
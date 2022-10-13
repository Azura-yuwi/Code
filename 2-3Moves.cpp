#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int solve(int n)
{
    if(n == 1) return 2;
    if(n%3 != 0) return (n/3) + 1;
    return n/3;
}


int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n; cin >> n;
        cout << solve(n) << endl;
    }
}
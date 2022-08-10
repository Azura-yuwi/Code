#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,k; cin >> n >> k;
    int pause[n];
    int highest = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> pause[i];
        pause[i] %= k;
        pause[i] *= 2;

        if(abs(k-pause[i]) < abs(k-pause[highest]))
        {
            highest = i;
        }
    } 

    cout << (highest+1);
}
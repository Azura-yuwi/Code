#include <bits/stdc++.h>
using namespace std;
#define ll long long

int coins[101];
int n;
ll num[1000001] = {-1};
ll mod = 1000000007;

void getWays(int src)
{
    num[src] = 0;

    for(int i = 0; i < n; i++)
    {
        if(src >= coins[i])
        {
            if(num[src-coins[i]] == -1)
            {
                getWays(src-coins[i]);
            }

            num[src] += num[src-coins[i]];
            num[src] = num[src]%mod;
        }
    }
}

int main()
{
    int x;
    cin >> n >> x;

    for(int i = 1; i <= x; i++)
    {
        num[i] = -1;
    }

    num[0] = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    getWays(x);
    
    cout << num[x];
}
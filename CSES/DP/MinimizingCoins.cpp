#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, x;
    cin >> n >> x;

    int coins[n];
    int num[x+1];
    for(int i = 0; i <= x; i++)
    {
        num[i] = INT_MAX;
    }

    num[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= coins[j] && num[i-coins[j]] != INT_MAX)
            {
                //cout << "ENTER " << num[i] << " " << num[i-coins[j]] << " " << coins[i] << endl;
                num[i] = min(num[i], num[i-coins[j]]);
            }
        }

        //cout << num[i] << endl;

        if(num[i] != INT_MAX)
        {
            num[i]++;
        }

        //cout << i << " " << num[i] << endl;
    }

    if(num[x] == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << num[x];
    }

}
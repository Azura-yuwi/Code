#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    int mod = 1000000007;
    cin >> n >> x;
    //scanf("%d%d", &n, &x);

    int coins[n];
    int num[1000001];

    for(int i = 0; i <= x; i++)
    {
        num[i] = 0;
    }
    //num[0] = 1;

    for (int i = 0; i < n; i++)
    {
        //scanf("%d", &coins[i]);
        cin >> coins[i];
        num[coins[i]] = 1;
    }

    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i > coins[j])
            {
                num[i] += num[i-coins[j]];
                num[i] = num[i]%mod;
            }
            //cout << i << " " << num[i] << " " << j << " " << coins[j] << endl;
        }
    }

    cout << num[x];
    //printf("%d", num[x]);
    return 0;
}

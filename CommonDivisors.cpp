#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int num[n];
    int divisors[1000001] = {0};

    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j*j <= num[i]; j++)
        {
            if(num[i]%j == 0)
            {
                divisors[j]++;

                if(num[i]/j != j)
                {
                    divisors[num[i]/j]++;
                }
            }
        }
    }

    for(int i = 1000000; i > 0; i--)
    {
        if(divisors[i] >= 2)
        {
            cout << i;
            break;
        }
    }

    return 0;
}
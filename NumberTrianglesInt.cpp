//ASCL 2020-2021 Contest 1 Intermediate

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int b = 8;

ll digitSum(ll num)
{
    int sum = 0;

    while(num > 0)
    {
        sum += num%b;
        num /= b;
    }

    return sum;
}

ll octToDec(ll num)
{
    ll ans = 0;
    while(num > 0)
    {
        ans += num%8;
        num /= 8;
    }

    return ans;
}


ll solv(int s, int delta, ll r)
{
    int num = octToDec(s);
    int sum = 0;

    for(int i = 1; i < r; i++)
    {
        for(int j = 0; j <= i; j++) //i+1 numbers
        {
            num += delta;

            if(i == r-1) //last row
            {
                sum += digitSum(num);
            }
        }
    }

    return sum;
}


int main()
{
    for(int i = 0; i < 5; i++)
    {
        ll s,d,r; cin >> s >> d >> r;
        cout << solv(s,d,r) << endl;
    }
}
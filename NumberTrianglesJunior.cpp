//ASCL 2020-2021 Contest 1 Intermediate

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int b = 10;

ll digitSum(ll num)
{
    ll sum = 0;

    while(num > 0)
    {
        sum += num%b;
        num /= b;
    }

    if(sum >= b)
    {
        sum = digitSum(sum);
    }

    return sum;
}

ll octToDec(string s)
{
    ll ans = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        ans *= 8;
        ans += (s[i]-'0');
    }

    return ans;
}


ll solv(ll s, ll d, ll r)
{
    int num = digitSum(s);
    int delta = d;
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
        ll s,d; ll r; cin >> s >> d >> r;
        cout << solv(s,d,r) << endl;
    }
}
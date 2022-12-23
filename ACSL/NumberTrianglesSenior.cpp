//ASCL 2020-2021 Contest 1 Senior

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int base = 16;

ll hexToDec(string s)
{
    ll ans = 0;

    for(int i = 0; i < s.size(); i++)
    {
        int digit;
        if(s[i]-'0' >= 0 && s[i]-'0' <= 9)
        {
            digit = s[i]-'0';
        }
        else
        {
            digit = s[i]-'A'+10;
        }

        ans *= 16;
        ans += digit;
    }

    return ans;
}

char decToHex(ll num)
{
    if(num < 10)
    {
        return (char)('0' + num);
    }

    return (char)('A' + num - 10);
}

ll digitSum(ll num, ll b)
{
    ll sum = 0;

    while(num > 0)
    {
        sum += num%b;
        num /= b;
    }

    return sum;
}


ll solv(string s, string d, ll r)
{
    int num = hexToDec(s);
    int delta = hexToDec(d);
    int sum = 0;

    for(int i = 1; i < r; i++)
    {
        for(int j = 0; j <= i; j++) //i+1 numbers
        {
            num += delta;

            if(i == r-1) //last row
            {
                sum += digitSum(num, base);
            }
        }
    }

    while(sum >= base)
    {
        sum = digitSum(sum, base);
    }

    return sum;
}


int main()
{
    for(int i = 0; i < 5; i++)
    {
        string s,d; ll r; cin >> s >> d >> r;
        cout << decToHex(solv(s,d,r)) << endl;
    }
}
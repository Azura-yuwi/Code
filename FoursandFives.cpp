#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    int ans = 1;
    int four = 0;
    int five = 0;

    while(four*4 < n)
    {
        if((n-four*4)%5 == 0)
        {
            five = (n-four*4)/5;
            break;
        }

        four++;
    }

    //cout << four << " " << five << endl;

    if(four*4 > n)
    {
        ans = 0;
    }
    else
    {
        ans += five/4;
    }

    cout << ans;
}
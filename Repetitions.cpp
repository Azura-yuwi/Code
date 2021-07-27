// CSES Intro Set
// Brute Force

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{  
    string s;
    cin >> s;
    int i = 0;
    int ans = 0;

    while(i < s.length())
    {
        char cur = s[i];
        int curlength = 1;
        i++;

        while(i < s.length() && s[i] == cur)
        {
            curlength++;
            i++;
        }

        ans = max(ans, curlength);
    }

    cout << ans;
}
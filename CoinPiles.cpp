//CSES Intro Set;
//Bash

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int a,b;
        cin >> a >> b;

        if( (a+b)%3 == 0 && a >= (a+b)/3 && b >= (a+b)/3)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}